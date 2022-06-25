//
// Created by Therence on 08/06/2022.
//

#ifndef MAIN_CPP_SOCKETMANAGER_H
#define MAIN_CPP_SOCKETMANAGER_H

// SockCPP
#include "sockpp/tcp_connector.h"

#include "ClientPacket.h"
#include "GUIState.h"
#include "ServerPacket.h"
#include "Constant.h"
#include <thread>

// For log purposes
#include "SDL.h"

enum ConnectState {
    TRYING_TO_CONNECT,
    NOT_CONNECTED,
    CONNECTED
};

class SocketManager {

private:
    ServerPacket serverPacket;

    ConnectState connectState = NOT_CONNECTED;
    ClientPacket * clientPacket;
    GUIState * guiState;
    string * errorMessage;
    thread socketThread;

    bool closeConnection;

    void clientThread();

public:

    SocketManager(ClientPacket * cliPacket, GUIState * gState, string * errMessage);

    void openSocket(); // Méthode appellée lorsque le joueur entre dans le menu de connexion au serveur

    void closeSocket(); // Close connections

    ServerPacket getServerPacket();

};


#endif //MAIN_CPP_SOCKETMANAGER_H
