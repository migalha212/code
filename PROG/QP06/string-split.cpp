#include <string>
#include <iostream>
#include "print_string.h"
using namespace std;

void split(const string& s, vector<string>& v){
    int temp1 = 0;
    for( unsigned long int i = 0; i < s.size(); i = temp1+1){
        temp1 = s.find(' ',i);
        if(s.substr(i,temp1-i).size() != 0){
            v.push_back(s.substr(i, temp1-i));
        }
        if(s.find(' ',i) == string::npos) break;
    }
}



int main(){
    { string s = "  a b  c ";
  vector<string> v;
  split(s, v);
  print(v); }
  return 0;
}