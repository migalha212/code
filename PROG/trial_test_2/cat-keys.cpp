#include <string>
#include <list>
#include <map>
#include <climits>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

string cat_keys(list<map<string, unsigned>> lst){
    auto it = lst.begin();
    unsigned curr = UINT_MAX;
    auto curr_it = it;
    while(it != lst.end()){
        for(pair<string,unsigned> p : *it){
            if(p.second < curr){
                curr = p.second;
                curr_it = it;
            }
        }
        it++;
    }
    ostringstream os;
    for(pair<string,unsigned> p : *curr_it){
        os << p.first;
    }
    return os.str();
}