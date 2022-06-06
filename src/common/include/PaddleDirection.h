//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_PADDLEDIRECTION_H
#define PONG_NETWORK_PADDLEDIRECTION_H

enum PaddleDirection {
    NONE = 0,
    PADDLE_DOWN = 1,
    PADDLE_UP = 2
};


static int getPaddleDirectionIndex(PaddleDirection paddleDir) {
    switch (paddleDir) {
        case NONE:
            return 0;
        case PADDLE_DOWN:
            return 1;
        case PADDLE_UP:
            return 2;
    }
}

#endif //PONG_NETWORK_PADDLEDIRECTION_H
