#include "GUI.h"
#include <ClientPacket.h>
#include <Constant.h>
#include <thread>
#include <Player.h>
#include "SocketManager.h"

int main(int argc, char *args[]) {

    try {

        // Initialisation des variables du jeu
        GUIState state = START_MENU;

        Player localPlayer;
        localPlayer.getNewRandomName();
        localPlayer.generateUUID();

        ClientPacket cp;
        cp.name = localPlayer.name;
        cp.uuid = localPlayer.uuid;

        string errorMessage, winnerName;

        GUI gui;

        SocketManager socket = SocketManager(&cp, &state, &errorMessage);

        // Initialisation de la partie graphique
        int sleep_time = 0;
        Uint32 next_game_tick = SDL_GetTicks();
        SDL_Event event;
        bool repeatedKey = false;

        // SDL Window setup
        if (gui.initGUI() == 1) {
            return EXIT_FAILURE;
        }

        // Render loop
        while (state != QUIT) {

            // Fermeture de la fenetre
            while ((state != QUIT) && SDL_PollEvent(&event)) {
                if ((event.type == SDL_WINDOWEVENT) && (event.window.event == SDL_WINDOWEVENT_CLOSE))
                    state = QUIT;
            }

            // Traiter les événements clavier
            const Uint8 *newKeystate = SDL_GetKeyboardState(nullptr);

            if (newKeystate[SDL_SCANCODE_ESCAPE]) {
                state = QUIT;
            }
            switch (state) {
                case START_MENU:
                    if (newKeystate[SDL_SCANCODE_RIGHT])
                        state = CONNECT_MENU;
                    if (!repeatedKey && newKeystate[SDL_SCANCODE_R]) {
                        repeatedKey = true;
                        localPlayer.getNewRandomName();
                    }
                    if (!newKeystate[SDL_SCANCODE_R]) {
                        repeatedKey = false;
                    }
                    break;
                case CONNECT_MENU:
                    socket.openSocket();
                    if (socket.getServerPacket().rightClient.name == localPlayer.name || socket.getServerPacket().leftClient.name == localPlayer.name) {
                        state = WAIT_MENU;
                    }
                    break;
                case WAIT_MENU:
                    if (socket.getServerPacket().isEnemyConnected(localPlayer)) {
                        state = INGAME_MENU;
                    }
                    if (newKeystate[SDL_SCANCODE_LEFT]) {
                        state = START_MENU;
                        socket.closeSocket();
                    }
                case INGAME_MENU:
                    cp.paddleDirection = NONE; // By default reset to none

                    if (socket.getServerPacket().gameState == GAME_OVER) {
                        if (socket.getServerPacket().rightClient.score == WIN_SCORE && socket.getServerPacket().leftClient.score == WIN_SCORE) {
                            winnerName = socket.getServerPacket().leftClient.name + " et " + socket.getServerPacket().rightClient.name + " sont a egalite";
                        } else if (socket.getServerPacket().rightClient.score == WIN_SCORE) {
                            winnerName = socket.getServerPacket().rightClient.name + " est le grand gagnant";
                        } else if (socket.getServerPacket().leftClient.score == WIN_SCORE) {
                            winnerName = socket.getServerPacket().leftClient.name + " est le grand gagnant";
                        }
                        state = WINNER_MENU;
                        socket.closeSocket();
                        break;
                    } else if (newKeystate[SDL_SCANCODE_DOWN] || newKeystate[SDL_SCANCODE_A]) {
                        cp.paddleDirection = PADDLE_DOWN;
                    } else if (newKeystate[SDL_SCANCODE_UP] || newKeystate[SDL_SCANCODE_Q]) {
                        cp.paddleDirection = PADDLE_UP;
                    }
                    break;
                case ERROR_MENU:
                    if (newKeystate[SDL_SCANCODE_LEFT]) {
                        state = START_MENU;
                        socket.closeSocket();
                    }
                default:
                    break;
            }

            // Draw background
            gui.updateBackground();

            switch (state) {
                case START_MENU:
                    gui.drawStartMenu(localPlayer.name);
                    break;

                case CONNECT_MENU:
                    gui.drawConnectMenu();
                    break;

                case WAIT_MENU:
                    gui.drawWaitMenu();
                    break;

                case INGAME_MENU:
                    gui.drawBall(socket.getServerPacket().ballX, socket.getServerPacket().ballY);
                    gui.drawPaddles(socket.getServerPacket().leftClient.paddleX, socket.getServerPacket().leftClient.paddleY, socket.getServerPacket().rightClient.paddleX, socket.getServerPacket().rightClient.paddleY);
                    gui.drawNet();
                    gui.drawScore(socket.getServerPacket().leftClient.name, socket.getServerPacket().rightClient.name, socket.getServerPacket().leftClient.score, socket.getServerPacket().rightClient.score);
                    break;

                case WINNER_MENU:
                    gui.drawWinnerMenu(socket.getServerPacket().leftClient.score, socket.getServerPacket().rightClient.score, winnerName);
                    break;

                case ERROR_MENU:
                    gui.drawErrorMenu(errorMessage);
                    break;

                default:
                    break;
            }

            // Draw to the display
            gui.updateDisplay();

            // Time it takes to render  frame in milliseconds
            next_game_tick += LOOP_TIME;
            sleep_time = next_game_tick - SDL_GetTicks();
            if (sleep_time > 0) {
                SDL_Delay(sleep_time);
            }

        }

        // Be sure to close conn if any
        socket.closeSocket();

        // Delete everything
        gui.quit();

    } catch (const std::exception& ex) {

        exception_ptr p = current_exception();
        SDL_Log("%s", (p ? p.__cxa_exception_type()->name() : "null"));

    }

    return EXIT_SUCCESS;
}


