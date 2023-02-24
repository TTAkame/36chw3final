#include "teamdata.h"
#include "priorityqueue.h"


int main(int argc, char** argv) {

    TeamData yawr(argv[1]);
    int i,j;
    double temp = 100.0;
    PriorityQueue ganr(yawr.numPlayers());
    
    for(i=0;i!=yawr.numPlayers()-1; i++){
        for(j=0;j!=yawr.numPlayers()-1;j++){
            if(temp-50.0>=yawr.winPercentages(i,j)-50.0){
                temp = yawr.winPercentages(i,j);
                //std::pair<double,std::pair(int,int)> x = {temp,{i,j}};
                KeyValuePair x ={temp,{i,j}};
                ganr.insert(x);
            }
        }
    }


}
