#include "GUI.h"
#include <ClientPacket.h>
#include <Constant.h>
#include <thread>
#include <Player.h>
#include "SocketManager.h"
#include <thread>

void lol(int i) {

}

int main(int argc, char *args[]) {
    try {

        // Initialisation des variables du jeu
        GUIState state = START_MENU;

        Player localPlayer, enemyPlayer;
        localPlayer.getNewRandomName();
        localPlayer.generateUUID();

        ClientPacket cp;
        cp.name = localPlayer.name;
        cp.uuid = localPlayer.uuid;

        bool tryingToConnect = false;
        string errorMessage;

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
                    if (!tryingToConnect) {
                        tryingToConnect = true;
                        socket.tryConnection();
                    }
                    break;
                case WAIT_MENU:
                    // TODO: Passer au menu INGAME_MENU dès lors qu'un enemi est indiqué dans le ServerPacket
                case INGAME_MENU:
                    if (newKeystate[SDL_SCANCODE_DOWN] || newKeystate[SDL_SCANCODE_A]) {
                        // TODO: Sauvegarder le contenu du prochain move du client a paddle down
                        cp.paddleDirection = PADDLE_DOWN;
                    } else if (newKeystate[SDL_SCANCODE_UP] || newKeystate[SDL_SCANCODE_Q]) {
                        // TODO: Sauvegarder le contenu du prochain move du client a paddle up
                        cp.paddleDirection = PADDLE_UP;
                    } else {
                        cp.paddleDirection = NONE;
                    }
                    break;
                default:
                    break;
            }

            // Draw background
            gui.updateBackground();

            switch (state) {
                case START_MENU:
                    gui.drawStartMenu(localPlayer.name);
                    //SDL_Log("draw start menu");
                    break;

                case CONNECT_MENU:
                    gui.drawConnectMenu();
                    //SDL_Log("draw connectClient menu");
                    break;

                case WAIT_MENU:
                    gui.drawWaitMenu();
                    //SDL_Log("draw wait menu");
                    break;

                case INGAME_MENU:
                    /*//check score
                    if (check_score() != 0) {
                        state = GAME_OVER;
                    } else {
                        //paddle ai movement
                        move_paddle_ai();

                        //* Move the balls for the next frame.
                        move_ball();
                        if (state != GAME_START) {
                            draw_net();
                            draw_paddle();
                            draw_ball();
                            draw_score();
                        }
                    }*/
                    break;

                case WINNER_MENU:
                    //SDL_Log("draw winnerMenu");

                    gui.drawWinnerMenu("bob");
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

        // Delete everything
        gui.quit();

    } catch (const std::exception& ex) {

        exception_ptr p = current_exception();
        SDL_Log("%s", (p ? p.__cxa_exception_type()->name() : "null"));

    }

    return EXIT_SUCCESS;
}


