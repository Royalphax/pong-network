//
// Created by there on 16/06/2022.
//

#include "SocketServer.h"

void clientThread(sockpp::tcp_socket sock, GameManager * game)
{
    cout << "NEW THREAD" << endl;
    string last_uuid, s_out, s_in;
    ssize_t n;

    auto t_start_tx = high_resolution_clock::now(), t_now = high_resolution_clock::now();
    sock.set_non_blocking(false);

    while (sock.is_open()) {
        // cout << "d1" << endl;
        t_start_tx = high_resolution_clock::now();
        // cout << "d2" << endl;
        // ------------ LECTURE  ------------
        s_in.resize(DATA_BUFFER_CLIENT);
        // cout << "d3" << endl;
        while (n != DATA_BUFFER_CLIENT && fpsec(t_now - t_start_tx).count() < SERVER_CLIENT_TIMEOUT) {
            n = sock.read_n(&s_in[0], DATA_BUFFER_CLIENT);
            t_now = high_resolution_clock::now();
            // cout << "d4" << endl;
        }
        // cout << "d5" << endl;
        // cout << n << endl;
//        if (game->players[0].uuid == last_uuid) {
//            cout << "---------------------------" << endl;
//            cout << "Data received : " << trim(s_in) << endl;
//        }

        if (n != DATA_BUFFER_CLIENT) {
            cout << "Error reading to the TCP stream: " << sock.last_error_str() << endl;
            break;
        }

        // cout << "d6" << endl;

        ClientPacket clientPacket;
        // cout << "d7" << endl;
        clientPacket.deserialize(s_in);
        // cout << "d8" << endl;
        last_uuid = clientPacket.uuid;
        // cout << "d9" << endl;
        game->updatePlayer(clientPacket);
        // cout << "d10" << endl;

        // cout << clientPacket.name + " : " << trim(s_in) << endl;
        // ------------ -------- ------------

        game->updatePacket();

        // ------------ ECRITURE ------------
        game->lockServerPacket();
        s_out = game->packet.serialize();
        game->unlockServerPacket();

        if (s_out.length() > DATA_BUFFER_SERVER) {
            cout << "Server buffer too small" << endl;
            break;
        }
        // cout << "d11" << endl;
//        if (game->players[0].uuid == last_uuid) {
//            cout << "Data sent : " << trim(s_out) << endl;
//        }

        if (sock.write_n(&s_out[0], DATA_BUFFER_SERVER) == -1) {
            cout << "Error writing to the TCP stream: " << sock.last_error_str() << endl;
            break;
        }
        // cout << "d12" << endl;


        // ------------ -------- ------------
    }

    // Inform that player disconnects
    cout << "d13" << endl;
    game->disconnectPlayer(last_uuid);
    cout << "d14" << endl;
    cout << "Connection closed from " << sock.peer_address() << endl;
    if (!sock.close()) {
        cout << "Error on closing stream: " << sock.last_error_str() << endl;
    }
}

void serverThread(GameManager * game)
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
            thread th1(clientThread, move(sock), game);
            th1.detach();
        }
    }
}

void startServer(GameManager * game) {
    thread th(serverThread, game);
    th.detach();
}