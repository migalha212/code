#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}
void count_words(const string& str, vector<pair<string, size_t>>& count){
istringstream inp(str);
string curr;
bool flag = 0;
while(inp >> curr){
    for(char &c: curr){c = tolower(c);}
    for(pair<string,size_t>& p : count){
        if(curr == p.first){p.second++;flag = true;break;}
    }
    if(!flag){count.push_back({curr,size_t(1)});continue;}
    flag = false;
}
sort(count.begin(),count.end());
}