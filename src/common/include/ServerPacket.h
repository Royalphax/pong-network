//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_SERVERPACKET_H
#define PONG_NETWORK_SERVERPACKET_H

#include <nlohmann/json.hpp>
#include <string>
#include <Constant.h>
#include "Player.h"
#include "GameState.h"
#include "Utils.h"

using namespace std;
using namespace nlohmann;

class ServerPacket { // Packet envoyé du serveur au client
public:
    int ballX, ballY;
    Player rightClient, leftClient;
    GameState gameState;

    ServerPacket() {
        ballX = ballY = 0;
        rightClient.paddleX = rightClient.paddleY = rightClient.score = 0;
        rightClient.name = "null";
        leftClient.paddleX = leftClient.paddleY = leftClient.score = 0;
        leftClient.name = "null";
        gameState = UNKNOWN;
    }

    bool isRight(const Player& me) const {
        return rightClient.name == me.name;
    }

    bool isEnemyConnected(const Player& me) const {
        if (rightClient.name == me.name && leftClient.name != "null") {
            return true;
        } else if (leftClient.name == me.name && rightClient.name != "null") {
            return true;
        }
        return false;
    }

    void updateLeftClient(const Player& player) {
        leftClient.paddleX = player.paddleX;
        leftClient.paddleY = player.paddleY;
        leftClient.score = player.score;
        leftClient.name = player.name;
    }

    void updateRightClient(const Player& player) {
        rightClient.paddleX = player.paddleX;
        rightClient.paddleY = player.paddleY;
        rightClient.score = player.score;
        rightClient.name = player.name;
    }

    string serialize() {
        json output;
        output["ballX"] = ballX;
        output["ballY"] = ballY;
        output["rightClient"]["paddleX"] = rightClient.paddleX;
        output["rightClient"]["paddleY"] = rightClient.paddleY;
        output["rightClient"]["score"] = rightClient.score;
        output["rightClient"]["name"] = rightClient.name;
        output["leftClient"]["paddleX"] = leftClient.paddleX;
        output["leftClient"]["paddleY"] = leftClient.paddleY;
        output["leftClient"]["score"] = leftClient.score;
        output["leftClient"]["name"] = leftClient.name;
        output["gameState"] = getGameStateIndex(gameState);
        string sOut = output.dump();
        while (sOut.length() < DATA_BUFFER_SERVER)
            sOut.append(" ");
        return sOut;
    }

    void deserialize(const string& input) {
        auto jsonInput = json::parse(trim(input));
        ballX = jsonInput["ballX"];
        ballY = jsonInput["ballY"];
        rightClient.paddleX = jsonInput["rightClient"]["paddleX"];
        rightClient.paddleY = jsonInput["rightClient"]["paddleY"];
        rightClient.score = jsonInput["rightClient"]["score"];
        rightClient.name = jsonInput["rightClient"]["name"];
        leftClient.paddleX = jsonInput["leftClient"]["paddleX"];
        leftClient.paddleY = jsonInput["leftClient"]["paddleY"];
        leftClient.score = jsonInput["leftClient"]["score"];
        leftClient.name = jsonInput["leftClient"]["name"];
        gameState = (GameState)jsonInput["gameState"];
    }
};

#endif //PONG_NETWORK_SERVERPACKET_H
