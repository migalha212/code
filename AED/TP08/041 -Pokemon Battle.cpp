#include <iostream>
#include <set>
using namespace std;

int main(){
    int a;
    cin >> a;
    multiset<int> aliceP;
    for(int i = 0; i < a; i++){
        int power;
        cin >> power;
        aliceP.insert(power);
    }
    int b;
    cin >> b;
    multiset<int> bobP;
    for(int i = 0; i < b; i++){
        int power;
        cin >> power;
        bobP.insert(power);
    }

    //* resolution

    while(!aliceP.empty() && !bobP.empty()){
        auto ita = aliceP.end();
        auto itb = bobP.end();
        int a = *--ita; aliceP.erase(ita);
        int b = *--itb; bobP.erase(itb);
        if(a == b){
            continue;
        }
        else if(a > b){
            aliceP.insert(a - b);
        }
        else
            bobP.insert(b - a);
    }

    if(aliceP.empty() && bobP.empty()){
        cout << "Tie" << endl;
        cout << '0' << endl;
    } else if(aliceP.empty()){
        cout << "Bob wins" << endl;
        cout << bobP.size() << endl;
    } else{
        cout << "Alice wins" << endl;
        cout << aliceP.size() << endl;
    }
}