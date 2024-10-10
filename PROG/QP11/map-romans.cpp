#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

unsigned roman_to_arab(const string& roman){

vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

unsigned save = 0;
unsigned total = 0;
for(char c : roman){
    for(pair<char,unsigned> d : roman_to_int){
        if (c == d.first){
            if(save < d.second) total -= (save*2);
            save = d.second;
        }
    }
    total += save;
}
return total;
}
