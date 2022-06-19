//
// Created by there on 06/06/2022.
//

#include "GameManager.h"
#include <Utils.h>

void GameManager::initGame() {
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;

    random_device r;
    mt19937 engine{r()};
    uniform_int_distribution<int> distrib1(0,2);
    ball.dy = distrib1(engine) - 1;
    ball.dx = distrib1(engine) - 1;

    mu.lock();
    players[0].paddleX = 20;
    players[0].paddleY = SCREEN_HEIGHT / 2 - 50 ;

    players[1].paddleX = SCREEN_WIDTH - 20 - 10;
    players[1].paddleY = SCREEN_HEIGHT / 2 - 50;
    mu.unlock();
}

void GameManager::moveBall() {
    // Move the ball by its motion vector.
    ball.x += ball.dx;
    ball.y += ball.dy;

    // Balle sortie laterale
    if (ball.x < 0) {
        mu.lock();
        players[1].score += 1;
        if (players[1].score == WIN_SCORE)
            gameState = GAME_OVER;
        mu.unlock();
        initGame();
        return;
    }

    if (ball.x > SCREEN_WIDTH - 10) {
        mu.lock();
        players[0].score += 1;
        if (players[0].score == WIN_SCORE)
            gameState = GAME_OVER;
        mu.unlock();
        initGame();
        return;
    }

    // Rebond sur partie haute ou basse
    if (ball.y < 0 || ball.y > SCREEN_HEIGHT - 10) {
        ball.dy = -ball.dy;
    }

    // Check for collision with the paddle
    mu.lock();
    for (const Player& player : players) {

        // Collision detected
        if (hasIntersection(ball.x, ball.y, BALL_HEIGHT, BALL_WIDTH, player.paddleX, player.paddleY, PADDLE_HEIGHT, PADDLE_WIDTH)) {

            // Accelerer la balle			
            ball.dx +=  (ball.dx < 0) ? -1: 1;
            // Change ball direction
            ball.dx = -ball.dx;

            // Change ball angle based on where on the paddle hitted it
            int hit_pos = (player.paddleY + PADDLE_HEIGHT) - ball.y;
            ball.dy = 4 - (int)(hit_pos / 7);
        }
    }
    mu.unlock();
}

void GameManager::movePaddle(Player * player) {
        if (player->paddleDir == NONE) {
            return;
        }

        if (player->paddleDir == PADDLE_DOWN) {
            // if the down arrow is pressed move paddle down
            player->paddleY += PADDLE_STEP;

            if (player->paddleY >= SCREEN_HEIGHT - PADDLE_HEIGHT) {
                player->paddleY = SCREEN_HEIGHT - PADDLE_HEIGHT;
            }
        } else if (player->paddleDir == PADDLE_UP) {
            // if the up arrow is pressed move paddle up
            player->paddleY -= PADDLE_STEP;

            if (player->paddleY <= 0) {
                player->paddleY = 0;
            }
        }
}

bool GameManager::isGameFull() {
    mu.lock();
    bool output = (players[0].name != "null" and players[1].name != "null");
    mu.unlock();
    return output;
}

void GameManager::updatePlayer(const ClientPacket& clientPacket) {
    // Mise à jour
    mu.lock();
    for (Player player : players)
        if (player.uuid == clientPacket.uuid) {
            player.paddleDir = clientPacket.paddleDirection;
            movePaddle(&player);
            if (player.uuid == players[0].uuid) {
                cout << player.name << ": " << player.paddleDir << " -> " << player.paddleY << endl;
            }
            mu.unlock();
            return;
        }
    // Inscription
    if (players[0].name == "null") {
        players[0].uuid = clientPacket.uuid;
        players[0].name = clientPacket.name;
    } else if (players[1].name == "null") {
        players[1].uuid = clientPacket.uuid;
        players[1].name = clientPacket.name;
    }
    mu.unlock();
}

void GameManager::disconnectPlayer(const string& uuid) {
    mu.lock();
    if (gameState == GAME_START) {
        players[0].clear();
    } else if (gameState == GAME_PLAY) {
        if (players[0].uuid == uuid) {
            players[0].score = 0;
            gameState = GAME_OVER;
        } else if (players[1].uuid == uuid) {
            players[1].score = 0;
            gameState = GAME_OVER;
        }
    }
    mu.unlock();
}
