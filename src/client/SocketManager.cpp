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


    while (true) {

        string s_out, s_in;
        // ------------ ECRITURE ------------
        s_out = clientPacket->serialize();

        if (s_out.length() > DATA_BUFFER_CLIENT) {
            SDL_Log("Data buffer client too small");
            *errorMessage = "Erreur buffer client trop petit";
            *guiState = ERROR_MENU;
            break;
        }

        conn.write(s_out);

        SDL_Log("Data sent : %s", trim(s_out).c_str());
        // ------------ -------- ------------

        // ------------ LECTURE  ------------
        s_in.resize(DATA_BUFFER_SERVER);
        ssize_t n = conn.read_n(&s_in[0], DATA_BUFFER_SERVER);

        if (n != DATA_BUFFER_SERVER) {
            SDL_Log("Error reading to the TCP stream: %s", conn.last_error_str().c_str());
            *errorMessage = "Erreur de lecture reseau";
            *guiState = ERROR_MENU;
            return;
        }

        SDL_Log("Data received : %s", trim(s_in).c_str());
        // ------------ -------- ------------

        this_thread::sleep_for(chrono::seconds(1));

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
