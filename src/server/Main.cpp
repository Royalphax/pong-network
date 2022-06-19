
#include <iostream>
#include "GameManager.h"
#include "SocketServer.h"


using namespace std;

int main(int argc, char* argv []) {

    GameManager game;
    game.gameState = GAME_START;

    ServerPacket packet;
    startServer(&game, &packet);

    while (1) { // Game process
        switch (game.gameState) {
            case GAME_START:
                if (game.isGameFull())
                    game.gameState = GAME_PLAY;
                    game.initGame();
                this_thread::sleep_for(chrono::seconds(1));
                break;

            case GAME_PLAY:
                game.moveBall();

                this_thread::sleep_for(chrono::milliseconds(10));
                break;

            case GAME_OVER:
                cout << "Game Over" << endl;
                this_thread::sleep_for(chrono::seconds(5));
                cout << "Restarting" << endl;
                game.mu.lock();
                for (Player player : game.players) player.clear();
                game.mu.unlock();
                game.gameState = GAME_START;
                break;

            default:
                // Do nothing
                break;
        }
        // Update server packet to send
        game.mu.lock();
        packet.updateLeftClient(game.players[0]);
        packet.updateRightClient(game.players[1]);
        game.mu.unlock();
        packet.gameState = game.gameState;
        packet.ballX = game.ball.x;
        packet.ballY = game.ball.y;

    }

    return 0;
}