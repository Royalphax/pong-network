//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_PLAYER_H
#define PONG_NETWORK_PLAYER_H

#include <list>
#include <string>
#include <stdexcept>
#include <utility>
#include <random>
#include <UUID.h>
#include "PaddleDirection.h"

using namespace std;

class Player {

private:
    static list<Player> users;
    list<string> usernames = {"War","Car","Macron","Cyber","Sea","Sunrise","Boy","Girl","Wolf","Rex","Black","Aura","Captain","Predator","Blue","Tyra","Pepito","Ghost","Russian","Bear","God","Lag","Zero","Colossus","Dick","Glass","Mario","Pika","Fist","First"};

public:
    string uuid = "null", name = "null";
    int score = 0, paddleX = 0, paddleY = 0;
    PaddleDirection paddleDir = NONE;

    void clear() {
        uuid = name = "null";
        score = paddleX = paddleY = 0;
        paddleDir = NONE;
    }

    void generateUUID() {
        uuid = UUID().to_string();
    }

    void getNewRandomName() {
        random_device r;
        mt19937 engine{r()};
        uniform_int_distribution<int> distrib1(0,(int) usernames.size() - 1);
        uniform_int_distribution<int> distrib2(0,1);

        string newName;
        while (newName.empty() || "Pong" + newName == name || newName + "Pong" == name) {
            auto it = usernames.begin();
            advance(it, distrib1(engine));
            newName = *it;
        }
        if (distrib2(engine)) {
            newName = newName + "Pong";
        } else {
            newName = "Pong" + newName;
        }
        name = newName;
    }

    static void createNewPlayer(string uuid, string name) {
        Player u;
        u.uuid = move(uuid);
        u.name = move(name);
        u.score = 0;
        users.push_back(u);
    }

    static Player getPlayerFromUUID(const string& uuid) {
        for (auto & user : users){
            if (user.uuid == uuid) {
                return user;
            }
        }
        throw out_of_range( "No player found for uuid " + uuid );
    }
};

#endif //PONG_NETWORK_PLAYER_H
