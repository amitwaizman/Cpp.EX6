#ifndef B_BALL_TEAM_H
#define B_BALL_TEAM_H
#include <string>
#include <vector>

namespace ariel{
class Team {
    public:
        std::string name;
        double level;
        char type;
        int Points;
        int win;
        int lose;
        std::string word;
        Team();
        Team(std::string &name, double level);
        int addPoints(int num);
        int winner();
        int lose1();




};
}

#endif //B_BALL_TEAM_H
