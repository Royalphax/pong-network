#include "GUI.h"
#include "GUIState.h"
#include "Constant.h"

GUIState state = START_MENU;

int main(int argc, char *args[]) {
    int sleep_time = 0;
    Uint32 next_game_tick = SDL_GetTicks();
    SDL_Event evenements;
    GUI gui;

    // SDL Window setup
    if (gui.initGUI() == 1) {
        return EXIT_FAILURE;
    }

    // Render loop
    while (state != QUIT) {

        // Fermeture de la fenetre
        while ((state != QUIT) && SDL_PollEvent(&evenements)) {
            if ((evenements.type == SDL_WINDOWEVENT) && (evenements.window.event == SDL_WINDOWEVENT_CLOSE))
                state = QUIT;
        }

        // Traiter les événements clavier
        const Uint8 *keystate = SDL_GetKeyboardState(nullptr);

        if (keystate[SDL_SCANCODE_ESCAPE]) {
            state = QUIT;
        }
        switch (state) {
            case START_MENU:
                if (keystate[SDL_SCANCODE_RIGHT])
                    state = CONNECT_MENU;
                if (keystate[SDL_SCANCODE_R]) {
                    // TODO: Changer pseudo de l'utilisateur parmis une liste
                }
                break;
            case CONNECT_MENU:
                if (keystate[SDL_SCANCODE_LEFT])
                    state = START_MENU;
                // TODO: Lancer la tentative de connexion au serveur (si ça fonctionne, passer au menu d'attente)
                break;
            case WAIT_MENU:
                // TODO: Passer au menu INGAME_MENU dès lors qu'un enemi est indiqué dans le ServerPacket
            case INGAME_MENU:
                if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_A]) {
                    // TODO: Sauvegarder le contenu du prochain move du client a paddle down
                }
                if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_Q]) {
                    // TODO: Sauvegarder le contenu du prochain move du client a paddle up
                }
                break;
            /*case GAME_OVER:
                if (keystate[SDL_SCANCODE_SPACE]) {
                    state = GAME_START;
                    score[0] = 0;    //reset scores
                    score[1] = 0;
                }
                break;*/
            case UNKNOWN:
                break;
            case WINNER_MENU:
                break;
            case QUIT:
                break;
        }

        // Draw background
        gui.updateBackground();

        switch (state) {
            case START_MENU:
                gui.drawStartMenu();
                SDL_Log("draw start menu");
                break;

            case CONNECT_MENU:
                gui.drawConnectMenu();
                SDL_Log("draw connect menu");
                break;

            case WAIT_MENU:
                gui.drawWaitMenu();
                SDL_Log("draw wait menu");
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
                gui.drawWinnerMenu();
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

    return EXIT_SUCCESS;
}
