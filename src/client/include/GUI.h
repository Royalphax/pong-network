//
// Created by there on 02/06/2022.
//

#ifndef PONG_NETWORK_GUI_H
#define PONG_NETWORK_GUI_H

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

using namespace std;

enum TextAlign {
    LEFT,
    CENTER,
    RIGHT
};

class GUI {

    SDL_Rect ball;
    SDL_Rect paddle[2];
    SDL_Window* window = nullptr;
    SDL_Renderer *renderer;
    SDL_Surface *screen;
    SDL_Texture *screen_texture;
    TTF_Font* fontBig;
    TTF_Font* fontNormal;
    TTF_Font* fontSmall;

public:
    int initGUI(); // Return 1 if error

    void drawText(int posX, int posY, const string& message, TTF_Font* police, TextAlign alignment = CENTER);

    void drawWinnerMenu(const string& winnerName);

    void drawStartMenu(const string& localPlayerName);

    void drawConnectMenu();

    void drawErrorMenu(string errorMessage);

    void drawWaitMenu();

    void drawScore(int scoreLeft, int scoreRight);

    void drawNet();

    void drawBall(int x, int y);

    void drawPaddles(int leftX, int leftY, int rightX, int rightY);

    void updateBackground();

    void updateDisplay();

    void quit();

};


#endif //PONG_NETWORK_GUI_H
