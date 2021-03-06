//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_GAMESTATE_H
#define PONG_NETWORK_GAMESTATE_H

enum GameState {
    UNKNOWN = 0,
    GAME_START = 1,
    GAME_PLAY = 2,
    GAME_OVER = 3
};

static int getGameStateIndex(GameState state) {
    switch (state) {
        case UNKNOWN:
            return 0;
        case GAME_START:
            return 1;
        case GAME_PLAY:
            return 2;
        case GAME_OVER:
            return 3;
    }
    return -1;
}

#endif //PONG_NETWORK_GAMESTATE_H
