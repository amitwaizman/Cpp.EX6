#include "Team.hpp"
#include "Leauge.hpp"
#include "Game.hpp"
#include "Schedule.hpp"
#include "doctest.h"
#include <string>
#include <algorithm>
using namespace ariel;
using namespace std;
TEST_CASE("Good input") {
    Leauge leauge1;
    std::string nameTeam[20] = {"A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
    leauge1.crateLeauge1(nameTeam);
            SUBCASE("check names"){
        Team t=leauge1.leaugeTeame[0];
        CHECK(((t.name)=="A")==true);
        Team t1=leauge1.leaugeTeame[1];
        CHECK(((t1.name)=="B")==true);
        Team t2=leauge1.leaugeTeame[2];
        CHECK(((t2.name)=="C")==true);
        Team t3=leauge1.leaugeTeame[3];
        CHECK(((t3.name)=="D")==true);
    }
        SUBCASE("size groups"){
        Schedule s(leauge1);
        int a=s.Equals();
        CHECK(((a)==122)== false);
        CHECK(((a)==1252)== false);
        CHECK(((a)==822)== false);
        int a1=s.MinPoints();
        CHECK(((a1)==121)== false);
        int a2=s.MaxPoints();
        CHECK(((a2)==159)== false);


    }

}

TEST_CASE("Bad input") {
    Leauge leauge1;
    std::string nameTeam[20] = {"jA", "pp","kC", "lD", "pE", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
    leauge1.crateLeauge1(nameTeam);
 SUBCASE("check names"){
            Team t=leauge1.leaugeTeame[0];
            CHECK_FALSE(((t.name)=="B"));
            Team t1=leauge1.leaugeTeame[1];
            CHECK_FALSE(((t1.name)=="B"));
            Team t2=leauge1.leaugeTeame[2];
            CHECK_FALSE(((t2.name)=="C"));
           Team t3=leauge1.leaugeTeame[2];
           CHECK_FALSE(((t3.name)=="C"));
           Team t4=leauge1.leaugeTeame[3];
           CHECK_FALSE(((t4.name)=="C"));
        Team t5=leauge1.leaugeTeame[3];
          CHECK_FALSE(((t5.name)=="C"));

        }
 SUBCASE("same name"){
        Leauge leauge2;
        std::string nameTeam[20] = {"A", "A","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
        CHECK_THROWS(leauge1.crateLeauge1(nameTeam));
        std::string nameTeam1[20] = {"C", "C","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
        CHECK_THROWS(leauge1.crateLeauge1(nameTeam1));
    }
 SUBCASE("size group"){
    Schedule s(leauge1);
    int a=s.Equals();
                CHECK_FALSE(((a)==15)==true);
    int a1=s.MinPoints();
                CHECK_FALSE(((a1)==153)==true);
    int a3=s.MaxPoints();
                CHECK_FALSE(((a3)==500)==true);
}
}