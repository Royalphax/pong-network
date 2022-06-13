//
// Created by Therence on 08/06/2022.
//

#include "SocketManager.h"

SocketManager::SocketManager(ClientPacket * cliPacket, GUIState * gState, string * errMessage) {
    clientPacket = cliPacket;
    guiState = gState;
    errorMessage = errMessage;
}

void SocketManager::tryConnection() {
    if (connectState != NOT_CONNECTED) return;
    connectState = TRYING_TO_CONNECT;

    std::thread socketThread(&SocketManager::clientThread, this);
    socketThread.detach();
    // Suspend execution of
    // calling thread
    // pthread_join(tid, NULL);

}

void SocketManager::clientThread() {

    string host = SERVER_HOST;
    in_port_t port = SERVER_PORT;

    sockpp::socket_initializer sockInit;

    // Implicitly creates an inet_address from {host,port}
    // and then tries the connection.

    sockpp::tcp_connector conn({host, port});
    if (!conn) {
        SDL_Log("Error connecting to server at %s, last error is %s", sockpp::inet_address(host, port).to_string().c_str(), conn.last_error_str().c_str());
        *errorMessage = "Erreur lors de la tentative de connexion";
        *guiState = ERROR_MENU;
        return;
    }

    SDL_Log("Created a connection from %s", conn.address().to_string().c_str());

    // Set a timeout for the responses
    if (!conn.read_timeout(chrono::seconds(5))) {
        SDL_Log("Error setting timeout on TCP stream: ", conn.last_error_str().c_str());
        *errorMessage = "Erreur de timeout";
        *guiState = ERROR_MENU;
    }

    string s, sret;
    while (true) {

        string json = clientPacket->serialize();
        SDL_Log("%s", json.c_str());

        if (conn.write(json) != ssize_t(json.length())) {
            SDL_Log("Error writing to the TCP stream: ", conn.last_error_str().c_str());
            *errorMessage = "Erreur d'écriture";
            *guiState = ERROR_MENU;
            break;
        }

        /*sret.resize(s.length());
        ssize_t n = conn.read_n(&sret[0], s.length());

        if (n != ssize_t(s.length())) {
            SDL_Log("Error reading to the TCP stream: ", conn.last_error_str().c_str());
            *errorMessage = "Erreur de lecture";
            *guiState = ERROR_MENU;
            break;
        }*/

        char buf[512];

        ServerPacket sp;

        int i = 0;
        while (conn.read(buf, sizeof(buf)) > 0) { i++; }
        if (i > 1) {
            SDL_Log("Error too much frame, need to increase buffer size");
        }

        SDL_Log("%s", buf);
        string json2 = buf;
        sp.deserialize(json2);

        SDL_Log("%s", json2.c_str());
        SDL_Log("%d", sp.ballX);

        return;
    }

    if (!conn) {
        SDL_Log("Wrong connexion");
        *errorMessage = "Erreur de connexion";
        *guiState = ERROR_MENU;
    }
}

ServerPacket SocketManager::getServerPacket() {
    return serverPacket;
}
