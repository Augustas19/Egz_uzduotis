#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

using std::getline;
using std::string;
using std::map;
using std::set;

void skt(map<string, int> daznis, map<string, set<int>> kur, set<string> url){
    
    std::ifstream F("text.txt");
    string eil;
    int eilsk=0;

    while (getline(F,eil)){
        eilsk++;


        std::stringstream s(eil);
    }
    
}

int main(){

map<string, int> daznis;
map<string, set<int>> kur;
set<string> url;

}