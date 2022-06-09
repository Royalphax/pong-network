//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_SERVERPACKET_H
#define PONG_NETWORK_SERVERPACKET_H

#include <nlohmann/json.hpp>
#include "GameState.h"
#include <string>

using namespace std;
using namespace nlohmann;

typedef struct Client {
    int paddleX, paddleY, score;
    string name;
} client;

class ServerPacket { // Packet envoyé du serveur au client
public:
    int ballX, ballY;
    Client rightClient, leftClient;
    GameState gameState;

    ServerPacket() {
        ballX = ballY;
        rightClient.paddleX = rightClient.paddleY = rightClient.score = 0;
        rightClient.name = "null";
        leftClient.paddleX = leftClient.paddleY = leftClient.score = 0;
        leftClient.name = "null";
        gameState = UNKNOWN;
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
        return output.dump();
    }

    void deserialize(const string& input) {
        auto jsonInput = json::parse(input);
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
