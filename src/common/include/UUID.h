//
// Created by there on 07/06/2022.
//

#ifndef PONG_NETWORK_UUID_H
#define PONG_NETWORK_UUID_H

#include <random>
#include <sstream>

using namespace std;

class UUID {

private:
    string uuid;

    std::string generate_v4() {
        random_device r;
        mt19937 gen{r()};
        uniform_int_distribution<int> dis(0, 15);
        uniform_int_distribution<int> dis2(8, 11);

        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return ss.str();
    }

public:

    UUID() {
        uuid = generate_v4();
    }

    string to_string() {
        return uuid;
    }

};

#endif //PONG_NETWORK_UUID_H
