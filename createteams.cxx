#include "teamdata.h"
#include "priorityqueue.h"
#include "teamdata.h"
#include<iostream>

int main(int argc, char** argv) {

    TeamData yawr(argv[1]);
    std::cout<<yawr.numPlayers();
    std::cout<<std::endl;
    std::cout<<yawr.winPercentages(1,1);
    
    int i;
    int j;
    int np=yawr.numPlayers();

    PriorityQueue ganr(np);

    for(i = 0; i < np; i++){
        for(j = i + 1; j < np; j++){
            ganr.insert(std::abs(yawr.winPercentages(i,j) - 50.0));
        }
    }

    KeyValuePair xs;
    nlohmann::json opn;

    for(int i = 0; i < np; i++) {
        xs = ganr.removeMin();
        opn = nlohmann::json::object();

        opn = xs.second.first;
        opn = xs.second.second;
        opn = yawr.winPercentages(xs.second.first, xs.second.second);

        std::cout << opn.dump(2) << std::endl;
    }

    return 0;
}

