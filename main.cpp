#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <regex>


using std::getline;
using std::string;
using std::map;
using std::set;
using std::regex;

string vienod(string zodis){
    string rez;
    for(char x : zodis){
        if(isalnum((unsigned char)x)){
            rez += tolower(x);
        }
    }
    return rez;
}

set<string> TLD(const string& failas){
    set<string> a;
    std::ifstream f(failas);
    if (!f){
        std::cout << "Nepavyko atidaryti TLD failo\n";
        return a;
    }
    string eil;
    while(getline(f, eil)){
        while (!eil.empty() && (eil.back() == '\r' || eil.back() == ' ')){
            eil.pop_back();
        }
        //if(eil.empty()||eil[0]=='#')continue;
        std::transform(eil.begin(), eil.end(), eil.begin(),
               [](unsigned char c){ return std::tolower(c); });
        a.insert(eil);
    }
}

bool valid(const string domain, const set<string> tinkamas){
    size_t pos = domain.find_last_of('.');
    if(pos == string::npos)
        return false;
    string tld = domain.substr(pos+1);
    std::transform(tld.begin(), tld.end(), tld.begin(),
            [](unsigned char c){ return std::tolower(c); });
    return tinkamas.count(tld)>0;
}

void skt(map<string, int> daznis, map<string, set<int>> kur, set<string> url, set<string> visidom){
    
    std::ifstream F("text.txt");
    if(!F){
        std::cout<<"Failo atidaryti neapvyko";
        return;
    }

    
    string eil;
    int eilsk=0;

    regex reurl(R"(((https?:\/\/)?(www\.)?[A-Za-z0-9\-]+\.[A-Za-z]{2,}(\/[^\s]*)?))");

    while (getline(F,eil)){
        eilsk++;
        //url
        std::sregex_iterator it(eil.begin(), eil.end(), reurl);
        std::sregex_iterator end;
        for(; it!=end; ++it){
            string gal = it->str();
            string domain = gal;
            //https
            if(domain.rfind("https://", 0)==0)
                domain=domain.substr(8);
            else if(domain.rfind("http://", 0)==0)
                domain=domain.substr(7);
            //www
            if(domain.rfind("www.", 0)==0)
                domain=domain.substr(4);
            //path
            size_t slashvieta = domain.find('/');
            if(slashvieta != string::npos)
                domain = domain.substr(0, slashvieta);
            
            if(valid(domain,visidom)){
                url.insert(gal);
            }
        }
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
    F.close();
}
void rasymasdazn(const map<string, int>& daznis){
    std::ofstream r("zodziai1.txt");
    for(const auto x : daznis){
        if(x.second > 1){
            r<<x.first<<" : "<<x.second<<"\n";
        }
    }
}
void rasymascross(const map<string, set<int>> kur){
    
}
int main(){

map<string, int> daznis;
map<string, set<int>> kur;
set<string> url;

set<string> visidom = TLD("domain.txt");

skt(daznis, kur, url, visidom);

}