//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_GAMEMANAGER_H
#define PONG_NETWORK_GAMEMANAGER_H

#include "PaddleDirection.h"
#include "GameState.h"
#include "Constant.h"
#include <string>
using namespace std;

typedef struct Ball {
    int x, y, w, h;
    int dx, dy; /* movement vector */
} virtualBall;

typedef struct Paddle {
    int x, y, w, h;
} virtualPaddle;

class GameManager {

private:
    Ball ball;
    GameState gameState;


public:
    GameManager();

    void initGame(); // Init position of ball and paddles

    string checkScore(); // Return the winner user unique id or empty string if no winner yet

    void moveBall(); // Move the ball at each tick

    void movePaddle(int userId, PaddleDirection paddleDir); // Move the paddle in the right direction

};


#endif //PONG_NETWORK_GAMEMANAGER_H
