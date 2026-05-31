#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <regex>
#include <algorithm>
#include "funkcijos.h"

using std::string;
using std::map;
using std::set;


int main(){
map<string, int> daznis;
map<string, set<int>> kur;
set<string> url;

set<string> visidom = TLD("domain.txt");

skt(daznis, kur, url, visidom);

rasymasdazn(daznis);
rasymascross(kur,daznis);
rasymasurl(url);
}