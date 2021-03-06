//
// Created by Therence on 08/06/2022.
//

#include "SocketManager.h"

SocketManager::SocketManager(ClientPacket * cliPacket, GUIState * gState, string * errMessage) {
    clientPacket = cliPacket;
    guiState = gState;
    errorMessage = errMessage;
    closeConnection = false;
}

void SocketManager::openSocket() {
    if (connectState != NOT_CONNECTED) return;

    connectState = TRYING_TO_CONNECT;
    closeConnection = false;

    socketThread = thread(&SocketManager::clientThread, this);
    socketThread.detach();
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
        *errorMessage = "Erreur serveur inaccessible";
        *guiState = ERROR_MENU;
        return;
    }

    SDL_Log("Connected from %s", conn.address().to_string().c_str());

    // Set a timeout for the responses
    if (!conn.read_timeout(chrono::seconds(5))) {
        SDL_Log("Error setting timeout on TCP stream: %s", conn.last_error_str().c_str());
        *errorMessage = "Erreur de timeout";
        *guiState = ERROR_MENU;
    }

    // Officialy connected
    connectState = CONNECTED;

    while (true) {

        if (closeConnection) {
            if (!conn.close()) {
                SDL_Log("Error on closing socket: %s", conn.last_error_str().c_str());
                *errorMessage = "Erreur lors de la fermeture de la connexion";
                *guiState = ERROR_MENU;
            }
            break;
        }

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

//        SDL_Log("-----------------------------------");
//        SDL_Log("Data sent : %s", trim(s_out).c_str());
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

        serverPacket.deserialize(s_in);
        // SDL_Log("Data received : %s", trim(s_in).c_str());
//        SDL_Log("-----------------------------------");
        // ------------ -------- ------------

        // this_thread::sleep_for(chrono::milliseconds (20));

    }

    if (!conn.close()) {
        SDL_Log("Error on closing stream: %s", conn.last_error_str().c_str());
        *errorMessage = "Erreur lors de la fermeture de la connexion";
        *guiState = ERROR_MENU;
    }

    SDL_Log("Disconnected");
}

ServerPacket SocketManager::getServerPacket() {
    return serverPacket;
}

void SocketManager::closeSocket() {
    closeConnection = true;
    connectState = NOT_CONNECTED;
    if (socketThread.joinable()) {
        socketThread.join();
    }
}
