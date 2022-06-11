//
// Created by Therence on 08/06/2022.
//

#ifndef MAIN_CPP_SOCKETMANAGER_H
#define MAIN_CPP_SOCKETMANAGER_H

#include <ClientPacket.h>
#include "GUIState.h"

class SocketManager {

private:
    // TODO: définir les variables privées nécessaires

public:
    // TODO: définir les variables publics nécessaires

    void connect(GUIState &state); // Méthode appellée lorsque le joueur entre dans le menu de connexion au serveur

    void sendPacket(const ClientPacket& cp);
    // TODO: rajouter les fonctions nécessaires pour se connecter/gérer la connexion
};


#endif //MAIN_CPP_SOCKETMANAGER_H
