#ifndef funkcijos_H
#define funkcijos_H

#include <string>
#include <set>
#include <map>

using std::string;
using std::map;
using std::set;

set<string> TLD(const string& failas);
bool valid(const string& domain, const set<string>& tinkamas);
void skt(map<string, int>& daznis, map<string, set<int>>& kur, set<string>& url, const set<string>& visidom);
void rasymasdazn(const map<string, int>& daznis);
void rasymascross(const map<string, set<int>> kur, const map<string, int>& daznis);
void rasymasurl(set<string>& url);
#endif