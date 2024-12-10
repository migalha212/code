#include <iostream>

#include <map>
using namespace std;


int main() {
    int n;
    cin >> n;
    map<int,int> coolcount;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num == 0) continue;
        if(coolcount.find(num) != coolcount.end()){
            coolcount[num]++;
        }
        else{
            coolcount[num] = 1;
        }
    }
    int removed = 0;
    for(pair<int,int> cool : coolcount){
        if(cool.first == cool.second) continue;
        else if(cool.second < cool.first){
            removed += cool.second;
        }
        else if(cool.second > cool.first){
            removed += cool.second - cool.first;
        }
    }
    cout << removed << endl;
}