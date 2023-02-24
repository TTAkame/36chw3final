#include "teamdata.h"
#include "json.hpp"
#include<fstream>
#include<string>


TeamData::TeamData(std::string file){


    std::ifstream file1(file);
    nlohmann::json data = nlohmann::json::parse(file1);

    int n = data["metadata"]["numPlayers"];

    numPlayers_ = n;


    for (auto& teamStat : data["teamStats"]) {
    int i = teamStat["playerOne"];
    int j = teamStat["playerTwo"];
    double winPercentage = teamStat["winPercentage"];

    winPercentages_[i][j] = winPercentage;
    }

}

int TeamData::numPlayers() const{
    return numPlayers_;
}



