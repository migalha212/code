#include <iostream>
#include <fstream>
#include "wc.h"
#include <string>
using namespace std;

wcresult wc(const string& filename){
    wcresult result = {0,0,0};
    string line;
    string word;
    ifstream f(filename);  //load file into f
    while(getline(f,line)){
        result.lines++;
        result.bytes += line.size() + 1;
        istringstream st(line);
        while(st >> word){result.words++;}
    }
    return result;
}

int main(){
    { wcresult r = wc("p2_test1.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
  return 0;
}