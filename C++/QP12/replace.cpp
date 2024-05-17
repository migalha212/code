#include <map>
#include <string>
using namespace std;

void replace(const map<char, char>& r, string& s){
    for(char & c : s){
        if(r.find(c) != r.end())  
            c = r.at(c);
    }
}