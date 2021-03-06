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

static bool hasIntersection(int objX1, int objY1, int objH1, int objW1, int objX2, int objY2, int objH2, int objW2) {
    int Amin, Amax, Bmin, Bmax;
    /* Horizontal intersection */
    Amin = objX1;
    Amax = Amin + objW1;
    Bmin = objX2;
    Bmax = Bmin + objW2;
    if (Bmin > Amin) {
        Amin = Bmin;
    }
    if (Bmax < Amax) {
        Amax = Bmax;
    }
    if (Amax <= Amin) {
        return false;
    }
    /* Vertical intersection */
    Amin = objY1;
    Amax = Amin + objH1;
    Bmin = objY2;
    Bmax = Bmin + objH2;
    if (Bmin > Amin) {
        Amin = Bmin;
    }
    if (Bmax < Amax) {
        Amax = Bmax;
    }
    if (Amax <= Amin) {
        return false;
    }
    return true;
}

#endif //PONG_NETWORK_UTILS_H
