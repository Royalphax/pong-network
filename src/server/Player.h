//
// Created by there on 06/06/2022.
//

#ifndef PONG_NETWORK_PLAYER_H
#define PONG_NETWORK_PLAYER_H

#include <list>
#include <string>
#include <stdexcept>
#include <utility>
using namespace std;

class Player {

private:
    static list<Player> users;

public:
    string uuid;
    string name;
    int score;

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
