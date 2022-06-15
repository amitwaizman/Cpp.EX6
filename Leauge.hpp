//
// Created by USER on 29/05/2022.
//

#ifndef B_BALL_LEAUGE_H
#define B_BALL_LEAUGE_H
#include <vector>
#include "Team.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
namespace ariel {
 class Leauge {
    public:
        int max = 20;
        std::string nameTeam[20] = {"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
        Team leaugeTeame[20];
        bool findString(std::string n[20]);
        Leauge& crateLeauge1(std::string n[20]);
        Leauge& crateLeauge2();
        Leauge& crateLeauge3(std::string n[10]);

    };
}


#endif //B_BALL_LEAUGE_H
