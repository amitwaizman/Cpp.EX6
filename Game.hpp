//
// Created by USER on 29/05/2022.
//

#ifndef B_BALL_GAME_H
#define B_BALL_GAME_H
#include "Team.hpp"
#include <iostream>
#include <string>
#include <random>
namespace ariel {
    class Game {
    public:
        Team A;
        Team B;

        Game(Team &A, Team &B);

    };
}


#endif //B_BALL_GAME_H
