//
// Created by there on 02/06/2022.
//

#include "GUI.h"
#include "Constant.h"

extern DECLSPEC int SDLCALL TTF_Init(void);

SDL_Color gameColor = {255, 255, 255, 255};

int GUI::initGUI() {
    int width, height;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window and renderer
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    if (window == nullptr) {
        SDL_Log("SDL_CreateWindowAndRenderer() SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    SDL_GetWindowSize(window, &width, &height);

    // Create the screen surface where all the elements will be drawn onto (ball, paddles, net etc)
    screen = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    if (screen == nullptr) {
        SDL_Log("Could not create the screen surface! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create the screen texture to render the screen surface to the actual display
    screen_texture = SDL_CreateTextureFromSurface(renderer, screen);
    if (screen_texture == nullptr) {
        SDL_Log("Could not create the screen_texture! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() < 0) {
        SDL_Log("Error ttf_init: %s\n", SDL_GetError());
        return 1;
    }

    fontBig = TTF_OpenFont("Pong.ttf", 72);
    if (!fontBig) {
        SDL_Log("TTF_OpenFont: %s\n", SDL_GetError());
        return 1;
    }

    fontNormal = TTF_OpenFont("Pong.ttf", 24);
    if (!fontNormal) {
        SDL_Log("TTF_OpenFont: %s\n", SDL_GetError());
        return 1;
    }

    fontSmall = TTF_OpenFont("Pong.ttf", 15);
    if (!fontSmall) {
        SDL_Log("TTF_OpenFont: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

void GUI::drawText(int posX, int posY, const string &message, TTF_Font *police, TextAlign alignment) {
    /**   Screen
     * |---------|
     * | 0,0     |
     * |      w,h|
     * |---------|
     */
    SDL_Surface *text_surface;
    SDL_Rect src;
    SDL_Rect dest;
    int newX, newY;

    if (!(text_surface = TTF_RenderText_Blended(police, message.c_str(), gameColor))) {
        SDL_Log("[TTF_RenderText_Blended] > %s", SDL_GetError());
    } else {
        src.x = 0;
        src.y = 0;
        src.w = text_surface->w;
        src.h = text_surface->h;

        switch (alignment) {
            case CENTER:
                newX = posX - (src.w / 2);
                break;
            case RIGHT:
                newX = posX - src.w;
                break;
            case LEFT:
                newX = posX;
                break;
        }
        newY = posY - (src.h / 2);

        dest.x = newX;
        dest.y = newY;
        dest.w = src.w;
        dest.h = src.h;

        SDL_BlitSurface(text_surface, &src, screen, &dest);
    }

    SDL_FreeSurface(text_surface);
}

void GUI::drawWinnerMenu() {
    char messageWinner[20] = "";
    int posX, posY;

    // TODO: Afficher le bon nom du gagnant
    strcpy(messageWinner, "Player 2 wins");

    posX = screen->w / 2;
    posY = screen->h / 2;

    drawText(posX, posY, messageWinner, fontBig);
    drawText(posX, posY + 90, "Game over", fontNormal);

    drawText(50, screen->h - 50, "[ECHAP] pour quitter", fontSmall, LEFT);
}

int blinkTextTick = 0;
#define MAX_BLINK_TEXT_TICK 50

void GUI::drawStartMenu() {
    int titleX, titleY;

    titleX = screen->w / 2;
    titleY = screen->h / 2;

    if (blinkTextTick > MAX_BLINK_TEXT_TICK)
        blinkTextTick = -MAX_BLINK_TEXT_TICK;

    drawText(titleX, titleY - 100, "Pong Network", fontBig);

    drawText(titleX, titleY, "Ton Pseudo :", fontSmall);
    drawText(titleX, titleY + 30, "Player1", fontNormal);

    if (blinkTextTick > 0)
        drawText(titleX, titleY + 100, "Appuyez sur [FLECHE DROITE] pour commencer", fontSmall);

    drawText(50, screen->h - 50, "[ECHAP] pour quitter", fontSmall, LEFT);
    drawText(50, screen->h - 75, "[R] pour changer pseudo", fontSmall, LEFT);

    blinkTextTick++;
}

int dotTick = 0;
#define MAX_DOT_TICK 119

void GUI::drawConnectMenu() {

    int titleX, titleY;

    titleX = screen->w / 2;
    titleY = screen->h / 2;

    if (dotTick > MAX_DOT_TICK)
        dotTick = 0;

    string dots = "Connexion";
    for (int i = 0; i < dotTick / 30; i++)
        dots += ".";

    drawText(titleX, titleY - 100, dots, fontBig);

    drawText(titleX, titleY, "Tentative de connexion au serveur", fontSmall);
    drawText(titleX, titleY + 30, "IP: 87.143.231.12", fontNormal);

    drawText(50, screen->h - 50, "[ECHAP] pour quitter", fontSmall, LEFT);
    //drawText(50, screen->h - 75, "[R] pour changer pseudo", fontSmall, LEFT);

    dotTick++;

}

void GUI::drawWaitMenu() {

    int titleX, titleY;

    titleX = screen->w / 2;
    titleY = screen->h / 2;

    if (dotTick > MAX_DOT_TICK)
        dotTick = 0;

    drawText(titleX, titleY - 100, "Connecte", fontBig);
    drawText(titleX, titleY, "Veuillez patienter", fontSmall);

    string dots = "En attente d'un adversaire";
    for (int i = 0; i < dotTick / 30; i++)
        dots += ".";

    drawText(titleX, titleY + 30, dots, fontNormal);

    drawText(50, screen->h - 50, "[ECHAP] pour quitter", fontSmall, LEFT);
    //drawText(50, screen->h - 75, "[R] pour changer pseudo", fontSmall, LEFT);

    dotTick++;
}


void GUI::drawScore() {
    /*char str_score[] = "0";

    str_score[0] = '0' + score[0];
    drawText( (screen->w/2) - 55, 20, str_score, fontBig );

    str_score[0] = '0' + score[1];
    drawText( (screen->w/2) + 55, 20, str_score, fontBig );*/
}

void GUI::drawNet() {
    SDL_Rect net;

    net.x = screen->w / 2;
    net.y = 0;
    net.w = 5;
    net.h = 15;

    for (int posY = 20; posY < screen->h - 30; posY += 30) {
        net.y = posY;

        if (SDL_FillRect(screen, &net, SCREEN_FG) != 0) {
            SDL_Log("fill rectangle failed in func draw_net()");
        }
    }
}

void GUI::drawBall() {
    if (SDL_FillRect(screen, &ball, SCREEN_FG) != 0) {
        SDL_Log("fill rectangle failed in func draw_ball()");
    }
}

void GUI::drawPaddle() {
    for (auto &i: paddle) {
        if (SDL_FillRect(screen, &i, SCREEN_FG) != 0) {
            SDL_Log("fill rectangle failed in func draw_paddle()");
        }
    }
}

void GUI::updateBackground() {
    SDL_RenderClear(renderer);
    SDL_FillRect(screen, nullptr, SCREEN_BG);
}

void GUI::updateDisplay() {
    SDL_UpdateTexture(screen_texture, nullptr, screen->pixels, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderCopy(renderer, screen_texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void GUI::quit() {
    SDL_FreeSurface(screen);

    // Free renderer and all textures used with it
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_CloseFont(fontBig);
    TTF_CloseFont(fontNormal);
    TTF_CloseFont(fontSmall);

    // Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();
}
