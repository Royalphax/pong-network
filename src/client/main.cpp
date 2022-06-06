#include "GUI.h"
#include "GUIState.h"
#include "Constant.h"

GUIState state = UNKNOWN;

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
        const Uint8 *keystate = SDL_GetKeyboardState(NULL);

        if (keystate[SDL_SCANCODE_ESCAPE]) {
            state = QUIT;
        }
        switch (state) {
            case START_MENU:
                if (keystate[SDL_SCANCODE_RIGHT])
                    // TODO: check if name filled
                    state = CONNECT_MENU;
                break;
            case CONNECT_MENU:
                if (keystate[SDL_SCANCODE_LEFT])
                    state = START_MENU;
                if (keystate[SDL_SCANCODE_RIGHT])
                    // TODO: try to connect to ip, if it works go to waiting menu
                break;
            case WAIT_MENU:
                // TODO: keep this menu while server packet has no enemy
            case INGAME_MENU:
                if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_A]) {
                    // TODO: save next move for client packet to down
                }
                if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_Q]) {
                    // TODO: save next move for client packet to up
                }
                break;
            /*case GAME_OVER:
                if (keystate[SDL_SCANCODE_SPACE]) {
                    state = GAME_START;
                    score[0] = 0;    //reset scores
                    score[1] = 0;
                }
                break;*/
        }

        // Draw background
        gui.updateBackground();

        /*switch (state) {
            case GAME_MENU:
                draw_menu();
                break;

            case GAME_START:
                init_game();
                state = GAME_PLAY;
                break;

            case GAME_PLAY:
                //check score
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
                }
                break;

            case GAME_OVER:
                draw_game_over();
                break;

            case GAME_QUIT:
                break;
        }*/

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
