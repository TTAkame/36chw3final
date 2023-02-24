#include "json.hpp"
#include<vector>
#include<string>
#include<fstream>
#include "priorityqueue.h"
#include<iostream>
int main(int argc, char** argv) {

    std::ifstream file1(argv[1]);

    nlohmann::json data = nlohmann::json::parse(file1);

    if(!file1.is_open()){
        std::cout<<"failed";
        return 0;
    }



    int msize = data["metadata"]["maxHeapSize"];
    // int numop = data["metadata"]["numOperations"];
    // int sizeh = data["metadata"]["size"];
    std::string opn; 
    double storekey;
    PriorityQueue runi(msize);
    for(auto it = data.begin();it != std::prev(data.end(),1);++it){
        opn = it.value()["operation"];
        if(opn=="insert"){
            storekey = it.value()["key"];
            runi.insert(storekey);
        }
        else if(opn=="removeMin"){
            runi.removeMin();
        }
   
    }
    nlohmann::json d = runi.JSON();
    d["metadata"]["numOperations"] = data["metadata"]["numOperations"];
    std::cout<<d.dump(2)<<std::endl;


    return 0;
}
