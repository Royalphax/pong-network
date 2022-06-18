//
// Created by there on 16/06/2022.
//

#include "SocketServer.h"

void clientThread(sockpp::tcp_socket sock, GameManager * game, ServerPacket * packet)
{
    string last_uuid;

    while (sock.is_open()) {

        string s_out, s_in;
        // ------------ LECTURE  ------------
        s_in.resize(DATA_BUFFER_CLIENT);
        ssize_t n = 0;
        while (n == 0) {
            n = sock.read_n(&s_in[0], DATA_BUFFER_CLIENT);
        }

        if (n != DATA_BUFFER_CLIENT) {
            cout << "Error reading to the TCP stream: " << sock.last_error_str() << endl;
            break;
        }

        ClientPacket clientPacket;
        clientPacket.deserialize(s_in);
        last_uuid = clientPacket.uuid;
        game->updatePlayer(clientPacket);

        cout << clientPacket.name + " : " << trim(s_in) << endl;
        // ------------ -------- ------------

        // ------------ ECRITURE ------------
        s_out = packet->serialize();

        if (s_out.length() > DATA_BUFFER_SERVER) {
            cout << "Server buffer too small" << endl;
            break;
        }

        if (sock.write(s_out) == -1) {
            cout << "Error writing to the TCP stream: " << sock.last_error_str() << endl;
            break;
        }

        //cout << "Data sent : " << trim(s_out) << endl;
        // ------------ -------- ------------
    }

    // Inform that player disconnects
    game->disconnectPlayer(last_uuid);

    cout << "Connection closed from " << sock.peer_address() << endl;
    if (!sock.close()) {
        cout << "Error on closing stream: " << sock.last_error_str() << endl;
    }
}

void serverThread(GameManager * game, ServerPacket * packet)
{
    cout << "Server started" << endl;

    in_port_t port = SERVER_PORT;

    sockpp::socket_initializer sockInit;

    sockpp::tcp_acceptor acc(port);

    if (!acc) {
        cerr << "Error creating the acceptor: " << acc.last_error_str() << endl;
    }

    cout << "Awaiting connections on port " << port << " ..." << endl;

    while (true) {
        sockpp::inet_address peer;

        // Accept a new client connection
        sockpp::tcp_socket sock = acc.accept(&peer);
        cout << "Received a connection request from " << peer << endl;

        if (!sock) {
            cerr << "Error accepting incoming connection: " << acc.last_error_str() << endl;
        }
        else {
            if (game->isGameFull()) {
                if (!sock.close())
                    cerr << "Error closing connection: " << acc.last_error_str() << endl;
                continue;
            }

            // Create a thread and transfer the new stream to it.
            thread th1(clientThread, move(sock), game, packet);
            th1.detach();
        }
    }
}

void startServer(GameManager * game, ServerPacket * packet) {
    thread th(serverThread, game, packet);
    th.detach();
}