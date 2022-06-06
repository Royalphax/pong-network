//
// Created by there on 02/06/2022.
//

#include "GUI.h"
#include "Constant.h"

extern DECLSPEC int SDLCALL TTF_Init(void);

SDL_Color gameColor = {255,255,255,255};

int GUI::initGUI() {
    int width, height;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window and renderer
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    if (window == NULL) {
        SDL_Log("SDL_CreateWindowAndRenderer() SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_GetWindowSize(window, &width, &height);

    // Create the screen surface where all the elements will be drawn onto (ball, paddles, net etc)
    screen = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    if (screen == NULL) {
        SDL_Log("Could not create the screen surface! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create the screen texture to render the screen surface to the actual display
    screen_texture = SDL_CreateTextureFromSurface(renderer, screen);
    if (screen_texture == NULL) {
        SDL_Log("Could not create the screen_texture! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() < 0) {
        SDL_Log( "Error ttf_init: %s\n", SDL_GetError() );
        return 1;
    }

    fontBig = TTF_OpenFont("Pong.ttf", 72);
    if(!fontBig) {
        SDL_Log("TTF_OpenFont: %s\n", SDL_GetError());
        return 1;
    }

    fontNormal = TTF_OpenFont("Pong.otf", 24);
    if(!fontNormal) {
        SDL_Log("TTF_OpenFont: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

void GUI::drawTextCenter(int posX, int posY, char *message, TTF_Font *police) {

}

void GUI::drawGameOver() {

}

void GUI::drawMenu() {

}

void GUI::drawScore() {

}

void GUI::drawNet() {

}

void GUI::drawBall() {

}

void GUI::drawPaddle() {

}

void GUI::updateBackground() {
    SDL_RenderClear(renderer);
    SDL_FillRect(screen, NULL, SCREEN_BG);
}

void GUI::updateDisplay() {
    SDL_UpdateTexture(screen_texture, NULL, screen->pixels, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderCopy(renderer, screen_texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void GUI::quit() {
    SDL_FreeSurface(screen);
    //free renderer and all textures used with it
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(fontBig);
    TTF_CloseFont(fontNormal);

    //Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();
}
