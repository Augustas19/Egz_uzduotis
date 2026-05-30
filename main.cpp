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

string vienod(string zodis){
    string rez;
    for(char x : zodis){
        if(isalnum((unsigned char)x)){
            rez += tolower(x);
        }
    }
    return rez;
}

void skt(map<string, int> daznis, map<string, set<int>> kur, set<string> url){
    
    std::ifstream F("text.txt");
    string eil;
    int eilsk=0;

    while (getline(F,eil)){
        eilsk++;
        // url

        //--

        // zodziai
        string zodis;
        std::stringstream s(eil);
        while(s>>zodis){
            zodis=vienod(zodis);
            if(zodis.empty())
                continue;
                
            daznis[zodis]++;
            kur[zodis].insert(eilsk);
        }
    }
    
}

int main(){

map<string, int> daznis;
map<string, set<int>> kur;
set<string> url;

}