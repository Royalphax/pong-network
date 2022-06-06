//
// Created by there on 02/06/2022.
//

#ifndef PONG_NETWORK_GUI_H
#define PONG_NETWORK_GUI_H

#include <SDL.h>
#include <SDL_ttf.h>

class GUI {

    SDL_Rect ball;
    SDL_Rect paddle[2];
    SDL_Window* window = NULL;
    SDL_Renderer *renderer;
    SDL_Surface *screen;
    SDL_Texture *screen_texture;
    TTF_Font* fontBig;
    TTF_Font* fontNormal;

public:
    int initGUI(); // Return 1 if error

    void drawTextCenter(int posX, int posY, char* message, TTF_Font* police);

    void drawGameOver();

    void drawMenu();

    void drawScore();

    void drawNet();

    void drawBall();

    void drawPaddle();

    void updateBackground();

    void updateDisplay();

    void quit();

};


#endif //PONG_NETWORK_GUI_H
