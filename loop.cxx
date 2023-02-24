#include<iostream>
#include<stdlib.h>
#include<fstream>
#include "json.hpp"
using namespace std;
int main(){
	ifstream file1("TestCase2.buildheap.json");
	nlohmann::json data = nlohmann::json::parse(file1);
int j=0;
string opn;
	for(auto it = data.begin();it != prev(data.end());++it){
	cout<<it.key(); 
	opn = it.value()["operation"];
        if(opn=="insert"){
      	j++;
      	}
        else if(opn=="removeMin"){
        j--;
	}
cout<<"xxxxxxxxxxxx"<<j<<endl;
	}
	return 0;

}

