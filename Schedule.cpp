#include "Schedule.hpp"
using  namespace ariel;

Schedule::Schedule(Leauge &leauge){
    this->l=leauge;
    this->Cycles.resize(20);
    for (unsigned long  i = 0; i < 20; ++i) {
        for (unsigned long k = 0; k < 20; ++k) {
            if(i!=k){
                this->l.leaugeTeame[i].type='H';
                this->l.leaugeTeame[k].type='O';
                this->Cycles[i].push_back(Game( this->l.leaugeTeame[i], this->l.leaugeTeame[k]));

            }
        }
    }
}

unsigned long  Schedule::findIndex(Team &t) {
    for (unsigned long i = 0; i < 20; ++i) {
       if(this->l.leaugeTeame[i].name==t.name){
           return i;
       }
    }
    return 21;
}

void Schedule::Table(){
    this->Cycles.resize(20);
    std::default_random_engine generator;
    std::default_random_engine generator1;
    std::normal_distribution<double > distribution(55.0,100.0);
    std::normal_distribution<double > distribution1(50.0,100.0);
    int out;
    int home;
    for (unsigned long i = 0; i < this->Cycles.size(); i++){
        for (unsigned long j = 0; j < this->Cycles[i].size(); j++) {
            home = distribution(generator);
            out = distribution1(generator1);
            if (home < 55) {
                home = (rand() % 55) + 55;
            }
            if (home > 100) {
                home = (rand() % 50) + 50;
            }
            if (out < 50) {
                out = (rand() % 50) + 50;
            }
            if (out > 100) {
                out = (rand() % 50) + 50;
            }

           unsigned long indexA= this->findIndex(this->Cycles.at(i).at(j).A);
          unsigned long indexB= findIndex(this->Cycles.at(i).at(j).B);
                if (this->l.leaugeTeame[indexA].type=='H'){
                    if(this->l.leaugeTeame[i].level>0.5&&home<91) {
                        home = home + 10;
                    }else{
                        this->l.leaugeTeame[indexA].Points+=home;
                    }
                }

                if (  this->l.leaugeTeame[indexA].type=='O'){
                    if(  this->l.leaugeTeame[i].level>0.5&&out<91) {
                        out = out + 10;
                    } else{
                        this->l.leaugeTeame[indexA].Points+=out;
                    }

                }
                   if (this->l.leaugeTeame[indexB].type == 'H') {
                       if (this->l.leaugeTeame[indexB].level > 0.5 && home < 91) {
                           home = home + 10;
                       } else {
                           this->l.leaugeTeame[indexB].Points +=home;
                       }
                   }
            if (this->l.leaugeTeame[indexB].type == 'O') {
                       if (this->l.leaugeTeame[indexB].level > 0.5 && out < 91) {
                           out = out + 10;
                       } else {
                           this->l.leaugeTeame[indexB].Points +=out;

                       }
               }



            if (this->l.leaugeTeame[indexB].Points<this->l.leaugeTeame[indexA].Points){
                this->l.leaugeTeame[indexA].win++;
                this->l.leaugeTeame[indexA].word+="w";
                this->l.leaugeTeame[indexB].word+="l";
                this->l.leaugeTeame[indexB].lose--;//= this->Cycles.at(i).at(j).B.lose1();

            } else{
                this->l.leaugeTeame[indexA].word+="l";
                this->l.leaugeTeame[indexB].word+="w";
                this->l.leaugeTeame[indexB].win++;//=this->Cycles.at(i).at(j).B.winner();
                this->l.leaugeTeame[indexA].lose--;//=this->Cycles.at(i).at(j).A.lose1();
            }
        }
   }

}

void Schedule::statistical_analysis(){
    this->ratio();
    cout<<"\n";
    this->remainder();
    cout<<"\n";
    this->Leading_groups();
    cout<<"\n";
    this->Sequence_length_Max();
    cout<<"\n";
    this->MaxPoints();
    cout<<"\n";
    this->MinPoints();
    cout<<"\n";
    this->Equals();
}

void Schedule::ratio(){
    this->Table();
    std::cout<<"ratio loss and win:\n";
    for (int i = 0; i <20 ; ++i) {
        int w= this->l.leaugeTeame[i].win;
        int l= this->l.leaugeTeame[i].lose;
        if(l<0){
            l=l*-1;
        }
        if(w<0){
            w= w*-1;
        }
        int r=abs(w/l);

        std::cout<<"name: "<< this->l.leaugeTeame[i].name<<" win: " <<w<<" lose: "<<l<<" p::"<<r<<"\n";
    }
}
int Schedule::MaxPoints(){
    this->Table();
    int count=0;
    std::cout<<"Teams scored more points than lost:\n";
    for (unsigned long i = 0; i <20 ; ++i) {
        if (this->l.leaugeTeame[i].win > abs(this->l.leaugeTeame[i].lose)) {
            count++;
            std::cout << "name: " << this->l.leaugeTeame[i].name << " ,";

        }
    }
        std::cout<<"\n";
        std::cout<<"size groups: "<< count;
    return count;
}
int Schedule::MinPoints(){
    this->Table();
    int count=0;
    std::cout<<"Min POINTS:\n";
    for (unsigned long i = 0; i <20 ; ++i) {
        if (abs(this->l.leaugeTeame[i].lose) > this->l.leaugeTeame[i].win) {
            count++;
            std::cout << "name: " << this->l.leaugeTeame[i].name << " ,";

        }
    }
    std::cout<<"\n";
    std::cout<<"size groups: "<< count;
    return count;
}

int Schedule::Equals(){
    this->Table();
    int count=0;
    std::cout<<"Equals POINTS:\n";
    for (unsigned long i = 0; i <20 ; ++i) {
        if (abs(this->l.leaugeTeame[i].lose) == this->l.leaugeTeame[i].win) {
            count++;
            std::cout << "name: " << this->l.leaugeTeame[i].name << " ,";

        }
    }
    std::cout<<"\n";
    std::cout<<"size groups: "<< count;
    return count;
}
//void Schedule::Points(){
//    this->Table();
//    for (unsigned long i = 0; i <20 ; ++i) {
//        int w= this->l.leaugeTeame[i].win;
//        int l= this->l.leaugeTeame[i].lose;
//        if(l<0){
//            l=l*-1;
//        }
//        if(w<0){
//            w= w*-1;
//        }
//        int r=abs(w-l);
//        if (this->l.leaugeTeame[i].win > this->l.leaugeTeame[i].lose) {
//            map.insert(this->l.leaugeTeame[i], r);
//        }
//
//    }
//
//}
void Schedule::Leading_groups(){
    this->Table();
    std::cout<<"Leading groups:\n";
    for (unsigned long i = 0; i <20 ; ++i) {
        if (this->l.leaugeTeame[i].win > this->l.leaugeTeame[i].lose) {
            std::cout << "name: " << this->l.leaugeTeame[i].name << " ,";

        }
    }

}

vector<int> Schedule::sum_number(string &s,char a){
    vector<int> v;
    int j=0;
    int size=s.size();
    for (unsigned long i = 0; i < size; ++i) {
        if(s[i]==a){
          j++;
        }else{

            v.push_back(j);
            j=0;
        }

    }
    return v;
}


void Schedule::remainder(){
    this->Table();
   std::cout<<"remainder:\n";
    for (int i = 0; i <20 ; ++i) {
     int w= this->l.leaugeTeame[i].win;
     int l= this->l.leaugeTeame[i].lose;
     if(l<0){
         l=l*-1;
     }
     if(w<0){
        w= w*-1;
     }
     int r=abs(w-l);

     std::cout<<"name: "<< this->l.leaugeTeame[i].name<<" win: " <<w<<" lose: "<<l<<" rem::"<<r<<"\n";
    }
}

void Schedule::Sequence_length_Max(){
    this->Table();
    unsigned long indexw=0;
    unsigned long indexl=0;
    int maxW=-1;
    int maxL=-1;
    std::cout<<"Sequence_length_Max win and lose:\n";
    for (int i = 0; i <20 ; ++i) {
        vector<int> v=sum_number(this->l.leaugeTeame[i].word, 'w');
        vector<int> v1 = sum_number(this->l.leaugeTeame[i].word, 'l');
        for (unsigned long j = 0; j < v.size(); ++j) {
            if (v.at(j)> maxW) {
               maxW = (int)v.at(j);
               indexw=j;
        }
        }
        for (unsigned long j = 0; j < v1.size(); ++j) {
            if (v1.at(j)> maxL) {
                maxL = (int)v1.at(j);
                indexw=j;
            }
        }
    }


        std::cout<<"name: "<< this->l.leaugeTeame[indexw].name<<"  len win: " <<maxW<<"\n";
        std::cout<<"name: "<< this->l.leaugeTeame[indexl].name<<"  len lose: " <<maxL<<"\n";


}



