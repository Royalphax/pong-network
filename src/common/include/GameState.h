//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_GAMESTATE_H
#define PONG_NETWORK_GAMESTATE_H

enum GameState {
    UNKNOWN = 0,
    WAITING_PLAYER = 1,
    GAME_START = 2,
    GAME_PLAY = 3,
    GAME_OVER = 4
};

static int getGameStateIndex(GameState state) {
    switch (state) {
        case UNKNOWN:
            return 0;
        case WAITING_PLAYER:
            return 1;
        case GAME_START:
            return 2;
        case GAME_PLAY:
            return 3;
        case GAME_OVER:
            return 4;
    }
    return -1;
}

#endif //PONG_NETWORK_GAMESTATE_H
