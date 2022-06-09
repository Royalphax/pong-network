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

using namespace std;

class Player {

private:
    static list<Player> users;
    list<string> usernames = {"CarPong","RoninPong","PongCyber","PongSea","SunrisePong","BoyPong","PongWolf","PongRex","BlackPong","AuraPong","CaptainPong","PongPredator"};

public:
    string uuid = "null";
    string name = "null";
    int score = 0;

    void generateUUID() {
        uuid = uuid::generate_uuid_v4();
    }

    void getNewRandomName() {
        random_device r;
        mt19937 engine{r()};
        uniform_int_distribution<int> distribution(0,(int) usernames.size() - 1);

        string newName = name;
        while (newName == name) {
            auto it = usernames.begin();
            advance(it, distribution(engine));
            newName = *it;
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
