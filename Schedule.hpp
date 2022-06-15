//
// Created by USER on 29/05/2022.
//

#ifndef B_BALL_SCHEDULE_H
#define B_BALL_SCHEDULE_H
#include "Game.hpp"
#include "Leauge.hpp"
#include "Team.hpp"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;
namespace ariel {
    class Schedule {
    public:
        Leauge l;
        map<Team, int> map;
        vector<vector<Game>> Cycles;
        Schedule(Leauge &leauge);
        void Table();
        unsigned long findIndex(Team& t);
        void Sequence_length_Max();
        int MaxPoints();
        int MinPoints();
       // void Points();
        void Leading_groups();
        vector<int> sum_number(string &s,char a);
        void ratio();
        void remainder();
        void statistical_analysis();
        int Equals();

    };
}


#endif //B_BALL_SCHEDULE_H
