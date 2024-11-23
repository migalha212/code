#include <iostream>
#include <map>
using namespace std;

int main(){
    int n = 0;
    cin >> n;

    map<int,int> meaningOfLife;
    for(int i = 0; i < n; i++){
        int life;
        cin >> life;
        if(meaningOfLife.find(life) != meaningOfLife.end()) {
            cout << meaningOfLife[life];
            meaningOfLife[life] = i + 1;
        }
        else{
            cout << -1;
            meaningOfLife[life] = i + 1;
        }
        if(i == n - 1) cout << endl;
        else cout << ' ';
    } 
}