//
// Created by there on 07/06/2022.
//

#ifndef PONG_NETWORK_GUISTATE_H
#define PONG_NETWORK_GUISTATE_H

enum GUIState {
    UNKNOWN = 0,
    START_MENU = 1, // Menu d'accueil et de choix du pseudo
    CONNECT_MENU = 2, // Menu de connexion et choix de l'@ip
    WAIT_MENU = 3, // Salle d'attente
    INGAME_MENU = 4, // En jeu
    WINNER_MENU = 5, // Affichage du gagnant
    QUIT = 6 // Quitte le jeu
};

#endif //PONG_NETWORK_GUISTATE_H
