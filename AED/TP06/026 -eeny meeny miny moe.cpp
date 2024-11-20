#include <iostream>
#include <list>
#include <string>
using namespace std;


/// @brief given a list with the names of the kids, and the word count of the game
/// @return The order in which they will be eliminated, with the last one being the Winner
/// @param people list with the name of the people that will be playing
/// @param wc   Word Count of the game to be played
void pimpampum(list<string> &people, int wc){
    //* set-up
    auto it = people.begin();
    //* main loop
    while (!people.empty())
    {
        int remainder = wc % people.size() - 1; // used to  determine how many people it will still go past without looping around

        if(remainder == -1) remainder = people.size() - 1; //* if -1 is returned it means it was one off from comming back to the starting point

        for(int i = 0; i < remainder; i++){
            it++;
            if(it == people.end()) it = people.begin();
        }

        cout << *it << endl;
        it = people.erase(it);
        if(it == people.end()) it = people.begin();
    }
    
}

int main(){
    //* setting up the variables
    string game;
    getline(cin, game);

    int n;
    cin >> n;
    list<string> people;
    for(int i = 0; i < n; i++){
        string name;
        cin >> name; people.push_back(name);
    }

    //* Word Count to be used for the solution (wc % #kids)
    int word_count = 1;
    for(char c : game){
        if(c == ' ') word_count++;
    }
    //* solution
    pimpampum(people,word_count);
}