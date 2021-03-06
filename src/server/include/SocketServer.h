//
// Created by there on 16/06/2022.
//

#ifndef PONG_NETWORK_SOCKETSERVER_H
#define PONG_NETWORK_SOCKETSERVER_H

#include <thread>
#include <chrono>
#include "sockpp/tcp_connector.h"
#include "sockpp/tcp_acceptor.h"
#include "ServerPacket.h"
#include "GameManager.h"

using namespace std;
using namespace std::chrono;

using fpsec = duration<double, seconds::period>;

void clientThread(sockpp::tcp_socket sock, GameManager * game);

void serverThread(GameManager * game);

void startServer(GameManager * game);

#endif //PONG_NETWORK_SOCKETSERVER_H
