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

static void run_echo(sockpp::tcp_socket sock)
{
    while (sock.is_open()) {

        string s_out, s_in;
        // ------------ LECTURE  ------------
        s_in.resize(DATA_BUFFER_CLIENT);
        ssize_t n = 0;
        while (n == 0) {
            n = sock.read_n(&s_in[0], DATA_BUFFER_CLIENT);
        }

        if (n != DATA_BUFFER_CLIENT) {
            cout << n << endl;
            cout << s_in << endl;
            cout << "Error reading to the TCP stream: " << sock.last_error_str() << endl;
            break;
        }

        cout << "Data received : " << trim(s_in) << endl;
        // ------------ -------- ------------

        ServerPacket sp;

        // ------------ ECRITURE ------------
        s_out = sp.serialize();

        if (s_out.length() > DATA_BUFFER_SERVER) {
            cout << "Server buffer too small" << endl;
            break;
        }

        sock.write(s_out);

        cout << "Data sent : " << trim(s_out) << endl;
        // ------------ -------- ------------
    }

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
