
#include <iostream>
#include "GameManager.h"
#include "SocketServer.h"


using namespace std;

int main(int argc, char* argv []) {

    GameManager game;
    game.gameState = GAME_START;

    startServer(&game);

    while (1) { // Game process
        switch (game.gameState) {
            case GAME_START:
                if (game.isGameFull()) {
                    game.gameState = GAME_PLAY;
                    game.initGame();
                }
                break;

            case GAME_PLAY:
                game.moveBall();
                this_thread::sleep_for(chrono::milliseconds(10));
                break;

            case GAME_OVER:
                cout << "Game Over" << endl;
                game.packet.gameState = GAME_OVER;
                this_thread::sleep_for(chrono::seconds(5));
                cout << "Restarting" << endl;
                game.lockPlayersData();
                for (auto & player : game.players) player.clear();
                game.unlockPlayersData();
                game.gameState = GAME_START;
                break;

            default:
                // Do nothing
                break;
        }
    }

    return 0;
}