//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_CLIENTPACKET_H
#define PONG_NETWORK_CLIENTPACKET_H

#include <string>
#include <nlohmann/json.hpp>
#include "PaddleDirection.h"

using namespace std;
using namespace nlohmann;

class ClientPacket { // Packet envoyé du client au serveur
public:
    string uuid;
    string name;
    PaddleDirection paddleDirection;

    ClientPacket() {
        uuid = "null";
        name = "null";
        paddleDirection = NONE;
    }

    string serialize() {
        json output;
        output["uuid"] = uuid;
        output["name"] = name;
        output["paddleDirection"] = getPaddleDirectionIndex(paddleDirection);
        return output.dump();
    }

    void deserialize(const string& input) {
        auto jsonInput = json::parse(input);

        uuid = jsonInput["uuid"];
        name = jsonInput["name"];
        paddleDirection = (PaddleDirection)jsonInput["paddleDirection"];
    }
};

#endif //PONG_NETWORK_CLIENTPACKET_H
