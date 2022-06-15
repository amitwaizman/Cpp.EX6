#include "Leauge.hpp"
using  namespace ariel;

bool Leauge::findString(std::string n[20]){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <20 ; ++j) {

            if(n[i]==n[j]&&i!=j){
                return false;
            }
        }
    }
    return true;
}

Leauge& Leauge::crateLeauge1(std::string n[20]) {
    bool a= findString(n);
    if(!a){
        throw std::out_of_range{"not good names"};
    }
    for (int i = 0; i < 20; ++i) {
        double l= ((double)rand()/(double)RAND_MAX);
        this->leaugeTeame[i]= Team(n[i],l);
    }
    return *this;
}

Leauge& Leauge::crateLeauge2() {
    std::string name;
    double l;
    for (int i = 0; i < this->max; ++i) {
        std::cout<<"enter name";
        std::cin>>name;
        std::cout<<"enter number [0,1]";
        std::cin>>l;
        if (l>1||l<0){
            throw std::out_of_range{"not good"};
        }
        this->leaugeTeame[i]= Team(nameTeam[i],l);
    }
    return *this;
}

Leauge& Leauge::crateLeauge3(std::string n[10]) {
    bool a= findString(n);
    std::cout<<a;
    if(!a){
        throw std::out_of_range{"not good names"};
    }
    std::string name;
    double l;
    for (int i = 0; i < this->max/2; ++i) {
        std::cout<<"enter name";
        std::cin>>name;
        std::cout<<"enter number [0,1]";
        std::cin>>l;
        if (l>1||l<0){
            throw std::out_of_range{"not good"};
        }
        this->leaugeTeame[i]= Team(name,l);
    }
    for (int i = 0; i < this->max/2; ++i) {
        double l= ((double)rand()/(double)RAND_MAX);
        this->leaugeTeame[i]= Team(n[i],l);
    }
    return *this;

}

