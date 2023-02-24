#include "teamdata.h"
#include "json.hpp"
#include<fstream>
#include<string>
#include<iostream>


TeamData::TeamData(std::string file){


    std::ifstream file1(file);
    if(!file1.is_open()){
        std::cerr<<"not open";
    }
    nlohmann::json data = nlohmann::json::parse(file1);

    int n = data["metadata"]["numPlayers"];

    numPlayers_ = n;
    winPercentages_.resize(n,std::vector<double>(n));
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            winPercentages_[i][j]=0.0;
        }
    }
    */

    nlohmann::json tstore = data["teamStats"];


    for (auto it = tstore.begin(); it !=tstore.end();++it) {
    int i = it.value()["playerOne"];
    int j = it.value()["playerTwo"];
    double winPercentage = it.value()["winPercentage"];



    winPercentages_[i][j] = winPercentage;

   // winPercentages_[j][i] = winPercentage;
    }

}

int TeamData::numPlayers() const{
    return numPlayers_;
}



