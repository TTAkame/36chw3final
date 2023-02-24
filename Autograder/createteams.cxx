#include "teamdata.h"
#include "priorityqueue.h"
#include "teamdata.h"
#include<iostream>

int main(int argc, char** argv) {

    TeamData yawr(argv[1]);
    
    int i,j;
    int np=yawr.numPlayers();
    
    PriorityQueue ganr((np*(np-1)/2));
    
    
    for(i=0;i<np-1;i++){
        for(j=i+1;j<np;j++){
            KeyValuePair yumi = std::make_pair(std::abs(yawr.winPercentages(i,j)-50.0),std::make_pair(i,j));
            ganr.insert(yumi);
            //ganr.insert(std::pair(std::abs(yawr.winPercentages(i,j)-50.0),std::pair(i,j)));
        }
    }

    std::cout<<ganr.JSON().dump(2)<<std::endl;  
    std::cout<<ganr.JSON().
    
    KeyValuePair xs;
    nlohmann::json opn;

    std::vector<int> ros;
    
    for(i=0;i<((np*(np-1)/2));i++){
        xs = ganr.removeMin();
        int b=xs.second.first;
        int c=xs.second.second;

        if((std::find(ros.begin(),ros.end(),b)==ros.end())&&(std::find(ros.begin(),ros.end(),c)==ros.end())){
            opn["teams"]+={b,c};
        }
        else{
            continue;
        }
        ros.push_back(b);
        ros.push_back(c);

    }
   
    std::cout<<opn.dump(2)<<std::endl;


    return 0; 
}
