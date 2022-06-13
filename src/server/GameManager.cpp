//
// Created by there on 06/06/2022.
//

#include "GameManager.h"

GameManager::GameManager() {

}

void GameManager::initGame() {
    /*ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.w = 10;
    ball.h = 10;
    ball.dy = 1;
    ball.dx = 1;

    paddle[0].x = 20;
    paddle[0].y = SCREEN_HEIGHT / 2 - 50 ;
    paddle[0].w = 10;
    paddle[0].h = 50;

    paddle[1].x = SCREEN_WIDTH - 20 - 10;
    paddle[1].y = SCREEN_HEIGHT / 2 - 50;
    paddle[1].w = 10;
    paddle[1].h = 50;*/
}

string GameManager::checkScore() {
    /*for(int i = 0; i < 2; i++)
        if ( score[i] == SCORE_WIN )
            return(i+1);

    return 0;*/
}

void GameManager::moveBall() {
    /*// Move the ball by its motion vector.
    ball.x += ball.dx;
    ball.y += ball.dy;

    // Balle sortie laterale
    if (ball.x < 0) {
        score[1] += 1;
        state  = GAME_START;
        return;
    }
    if (ball.x > SCREEN_WIDTH - 10) {
        score[0] += 1;
        state  = GAME_START;
        return;
    }

    // Rebond sur partie haute ou basse
    if (ball.y < 0 || ball.y > SCREEN_HEIGHT - 10) {
        ball.dy = -ball.dy;
    }

    //check for collision with the paddle
    for (int i = 0; i < 2; i++) {

        //collision detected	
        if ( SDL_HasIntersection(&ball, &paddle[i]) ) {

            // Accelerer la balle			
            ball_move.dx +=  (ball_move.dx < 0) ? -1: 1;
            //change ball direction
            ball_move.dx = -ball_move.dx;

            //change ball angle based on where on the paddle it hit
            int hit_pos = (paddle[i].y + paddle[i].h) - ball.y;
            ball_move.dy = 4 - (int)(hit_pos / 7);
        }
    }*/
}

void GameManager::movePaddle(int userId, PaddleDirection paddleDirection) {
    /*if (paddleDirection == PADDLE_DOWN) {
        // if the down arrow is pressed move paddle down
        paddle[paddleNum].y += 5;

        if(paddle[paddleNum].y >= SCREEN_HEIGHT - paddle[paddleNum].h) {
            paddle[paddleNum].y = SCREEN_HEIGHT - paddle[paddleNum].h;
        }
    } else if (paddleDirection == PADDLE_UP) {
        // if the up arrow is pressed move paddle up
        paddle[paddleNum].y -= 5;

        if(paddle[paddleNum].y <= 0) {
            paddle[paddleNum].y = 0;
        }
    }*/
}

