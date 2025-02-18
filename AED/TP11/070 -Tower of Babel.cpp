#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
using namespace std;


bool nextWord(string &line,string &word){
    for(int i = 0; i < line.size();i++){
        line[i] = tolower(line[i]);
        if(!isalpha(line[i])){
            word = line.substr(0,i);
            line = line.substr(i + 1, line.size() - i);
            return true;
        }
        if(i == line.size() - 1){
            word = line;
            line = "";
            return true;
        }
    }
    return false;
}

int main() {
    int n; // number of languages to consider
    cin >> n;
    vector<unordered_map<string,int>> dictionary;
    vector<pair<string, int>> languages;
    for (int i = 0; i < n; i++) {
        string lang;
        int words;
        cin >> lang >> words;
        unordered_map<string,int> temp;
        languages.push_back({lang,0});
        for (int j = 0; j < words; j++) {
            string word;
            cin >> word;
            temp.insert({word,i});
        }
        dictionary.push_back(temp);
    }
    string line;
    string word;
    getline(cin, line);
    getline(cin,line);
    while (nextWord(line,word)) {
        if(word.size() == 0) continue;
        for(unordered_map<string,int> language : dictionary){
            if(language.find(word) != language.end()) languages[language[word]].second++;
        }
    }
    for (pair<string, int> count : languages) {
        cout << count.first << ": " << count.second << endl;
    }
}