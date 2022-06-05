//
// Created by Therence on 03/06/2022.
//

#ifndef MAIN_CPP__CLIENTPACKET_H
#define MAIN_CPP__CLIENTPACKET_H

#include "PaddleDirection.h"
#include <iostream>

class ClientPacket {

public:

    paddle_direction paddleDirection;

    ClientPacket() {
        paddleDirection = NONE;
    }

    char serialize() const {
        switch (paddleDirection) {
            case NONE:
                return (char)0;
            case PADDLE_DOWN:
                return (char)1;
            case PADDLE_UP:
                return (char)2;
        }
    }

    static ClientPacket deserialize(char serial) {
        auto *packet = new ClientPacket();
        switch ((int)serial) {
            case 0:
                packet->paddleDirection = NONE;
            case 1:
                packet->paddleDirection = PADDLE_DOWN;
            case 2:
                packet->paddleDirection = PADDLE_UP;
        }
        return *packet;
    }

};


#endif //MAIN_CPP__CLIENTPACKET_H
