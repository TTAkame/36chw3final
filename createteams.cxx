#include "teamdata.h"
#include "priorityqueue.h"
#include "teamdata.h"
#include<iostream>

int main(int argc, char** argv) {

    TeamData yawr(argv[1]);
    std::cout<<yawr.numPlayers();
    std::cout<<std::endl;
    std::cout<<yawr.winPercentages(1,1);
    int i,j;
    int np=yawr.numPlayers();
    PriorityQueue ganr(np);
    for(i=0;i<np;i++){
        for(j=i+1;j<np;j++){
            ganr.insert(std::abs(yawr.winPercentages(i,j)-50.0));
        }
    }
    KeyValuePair xs;
    nlohmann::json opn;
    for(i=0;i<np;i++){
        xs = ganr.removeMin();
        opn

    }
    //std::cout<<ganr.JSON().dump(2)<<std::endl;
    
}
