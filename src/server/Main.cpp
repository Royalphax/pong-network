
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
                this_thread::sleep_for(chrono::milliseconds(200));
                break;

            case GAME_PLAY:
                game.moveBall();
                this_thread::sleep_for(chrono::milliseconds(10));
                break;

            case GAME_OVER:
                cout << "Game Over" << endl;
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
        // Update server packet to send
        game.lockServerPacket();
        game.lockPlayersData();
        game.packet.updateLeftClient(game.players[0]);
        game.packet.updateRightClient(game.players[1]);
        game.unlockPlayersData();
        game.packet.gameState = game.gameState;
        game.packet.ballX = game.ball.x;
        game.packet.ballY = game.ball.y;
        game.unlockServerPacket();

    }

    return 0;
}