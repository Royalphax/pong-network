//
// Created by there on 11/06/2022.
//

#ifndef PONG_NETWORK_SERVER_H
#define PONG_NETWORK_SERVER_H

#include <ServerPacket.h>
#include <ClientPacket.h>
#include <iostream>
#include <thread>
#include "sockpp/tcp_acceptor.h"
#include <Constant.h>

using namespace std;

// --------------------------------------------------------------------------
// The thread function. This is run in a separate thread for each socket.
// Ownership of the socket object is transferred to the thread, so when this
// function exits, the socket is automatically closed.

static void run_echo(sockpp::tcp_socket sock)
{

    string s, sret;

    sret.resize(BUFFER_SIZE);
    ssize_t n = sock.read(nullptr);

    if (n != ssize_t(BUFFER_SIZE)) {
        cout << "Error reading to the TCP stream: " << sock.last_error_str() << endl;
        return;
    }

    cout << sret << endl;

    return;





    ServerPacket sp;
    string json = sp.serialize();
    cout << json << endl;
    cout << sizeof(json) << endl;
    cout << json.length() << endl;
    cout << json.size() << endl;
    cout << json.max_size() << endl;


    /*
    ClientPacket cp;
    ServerPacket sp;

    int i = 0;
    while (sock.read(buf, sizeof(buf)) > 0) { i++; }
    if (i > 1) {
        cout << "ERREUR TRAME DECOUPEE" << endl;
    }

    string buffer = buf;
    cout << buffer << endl;
    cp.deserialize(buf);

    cout << cp.name.c_str() << endl;
    cout << cp.uuid.c_str() << endl;

    string json = sp.serialize();
    cout << json << endl;

    sock.write(json);*/

    cout << "Connection closed from " << sock.peer_address() << endl;
}

// --------------------------------------------------------------------------
// The main thread runs the TCP port acceptor. Each time a connection is
// made, a new thread is spawned to handle it, leaving this main thread to
// immediately wait for the next connection.

static int start()
{
    in_port_t port = SERVER_PORT;

    sockpp::socket_initializer sockInit;

    sockpp::tcp_acceptor acc(port);

    if (!acc) {
        cerr << "Error creating the acceptor: " << acc.last_error_str() << endl;
        return 1;
    }
    //cout << "Acceptor bound to address: " << acc.address() << endl;
    cout << "Awaiting connections on port " << port << "..." << endl;

    while (true) {
        sockpp::inet_address peer;

        // Accept a new client connection
        sockpp::tcp_socket sock = acc.accept(&peer);
        cout << "Received a connection request from " << peer << endl;

        if (!sock) {
            cerr << "Error accepting incoming connection: "
                 << acc.last_error_str() << endl;
        }
        else {
            // Create a thread and transfer the new stream to it.
            thread thr(run_echo, std::move(sock));
            thr.detach();
        }
    }

    return 0;
}

#endif //PONG_NETWORK_SERVER_H
