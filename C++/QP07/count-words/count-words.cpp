#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int count(const string& fname, const string& word){
    string w2 = word; for(char& c : w2){c = tolower(c);}
    string w1;
    ifstream f(fname);
    int counter = 0;
    while(f >> w1){
        for(char& c : w1){c = tolower(c);}
        if(w1 == w2){
            counter++;
        }
        }
        return counter;
    }

int main(){
    cout << count("p1_test_a.txt", "THE") << '\n';
    cout << count("p1_test_b.txt", "you") << '\n';
    return 0;
}

