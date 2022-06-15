#include "Team.hpp"
#include "Leauge.hpp"
#include "Game.hpp"
#include "Schedule.hpp"
using namespace ariel;
using namespace std;

int main() {
    Leauge leauge1;
    std::string nameTeam[20] = {"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
    leauge1.crateLeauge1(nameTeam);
    Schedule s(leauge1);
    s.statistical_analysis();

}
