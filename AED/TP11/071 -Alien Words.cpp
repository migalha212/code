#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

int main(){
    int n; // number of languages to consider
    cin >> n;
    unordered_map<string,string> dictionary;
    unordered_map<string,int> languages;
    for(int i = 0; i < n; i++){
        string lang;
        int words;
        cin >> lang >> words;
        languages[lang] = 0;
        for(int j = 0; j < words; j++){
            string word;
            cin >> word;
            dictionary[word] = lang;
        }
    }

    string line;
    getline(cin,line);
    stringstream ss(line);
    string word;
    while(ss >> word){
        if(dictionary.find(word) != dictionary.end())
            languages[dictionary[word]]++;
    }
    for(pair<string,int> count : languages){
        cout << count.first << ": " << count.second << endl;
    }
}