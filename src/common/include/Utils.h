//
// Created by there on 15/06/2022.
//

#ifndef PONG_NETWORK_UTILS_H
#define PONG_NETWORK_UTILS_H

#include <regex>

using namespace std;

static string trim(const string &s) {
    string s1 = regex_replace(s, regex("\\s+$"), string(""));
    return regex_replace(s1, regex("^\\s+"), string(""));
}

#endif //PONG_NETWORK_UTILS_H
