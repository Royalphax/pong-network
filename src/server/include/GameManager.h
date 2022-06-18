//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_GAMEMANAGER_H
#define PONG_NETWORK_GAMEMANAGER_H

#include "PaddleDirection.h"
#include "GameState.h"
#include "Constant.h"
#include "ClientPacket.h"
#include <string>
#include "Player.h"
#include <iostream>

using namespace std;

typedef struct Ball {
    int x = 0, y = 0;
    int dx = 0, dy = 0; /* movement vector */
} virtualBall;

class GameManager {

public:
    GameState gameState = UNKNOWN;
    virtualBall ball;
    Player players[2] = {Player(), Player()};

    void initGame(); // Init position of ball and paddles

    void moveBall(); // Move the ball at each tick

    void movePaddle(Player player, PaddleDirection paddleDirection); // Move the paddle in the right direction

    bool isGameFull();

    void updatePlayer(const ClientPacket& clientPacket);

    void disconnectPlayer(string uuid);

};


#endif //PONG_NETWORK_GAMEMANAGER_H
