#include <bits/stdc++.h> 
using namespace std;


void count_words(const string& str, map<string, size_t>& count){
    stringstream iss(str);
    string word = "";
    while(iss >> word)
    {
        for(char &c : word){
            c = tolower(c);
        }
        if(count.find(word) != count.end()) count.at(word)++;
        else count.insert({word,1});
    }

}

void show_map(const map<string, size_t>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}