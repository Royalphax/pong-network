//
// Created by there on 07/06/2022.
//

#ifndef PONG_NETWORK_GUISTATE_H
#define PONG_NETWORK_GUISTATE_H

enum GUIState { // Enum pour savoir dans quel menu le client se trouve
    NO_MENU = 0,
    START_MENU = 1, // Menu d'accueil et de choix du pseudo
    CONNECT_MENU = 2, // Menu de connexion et choix de l'@ip
    WAIT_MENU = 3, // Salle d'attente
    // Pour savoir si il n'y a pas de joueur pret en face, le ServerPacket indique comme nom d'enemy 'null'.
    // On reste donc dans le WAIT MENU tant qu'aucun nom de joueur enemy n'est défini

    INGAME_MENU = 4, // En jeu
    WINNER_MENU = 5, // Affichage du gagnant
    ERROR_MENU = 6, // Erreur de connexion ou dans le jeu
    QUIT = 7 // Quitte le jeu
};

#endif //PONG_NETWORK_GUISTATE_H
