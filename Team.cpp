#include "Team.hpp"
namespace ariel{
Team::Team(std::string &name, double level) {
    this->level=level;
    this->name=name;
    this-> Points=0;
    this->type='N';
    this->win=0;
    this->lose=0;
}

Team::Team() {

}

    int Team::addPoints(int num){
        this->Points+=num;
        return this->Points;
}
    int Team::winner(){
        this->win+=1;
        return this->win;
    }
    int Team::lose1(){
        this->lose+=1;
        return this->lose;
    }
}