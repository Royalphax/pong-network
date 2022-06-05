//
// Created by Therence on 05/06/2022.
//

#ifndef MAIN_CPP_SERVERPACKET_H
#define MAIN_CPP_SERVERPACKET_H

#include "GameState.h"

public:

    int ballX, ballY;
    int paddleX, paddleY;
    int clientScore, enemyScore;
    game_state gameState;

    ServerPacket() {
        ballX = ballY = 0;
        paddleX = paddleY = 0;
        clientScore = enemyScore = 0;
        gameState = GAME_MENU
    }

    char serialize() const {
        return true;
    }

    static ClientPacket deserialize(char serial) {
    }

#endif //MAIN_CPP_SERVERPACKET_H
