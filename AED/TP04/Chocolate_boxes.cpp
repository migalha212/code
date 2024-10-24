#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int boxes,friends;
    cin >> boxes >> friends;
    vector<int> chocolates(boxes);
    for(int i = 0; i < boxes; i++){
        cin >> chocolates[i];
    }
sort(chocolates.begin(),chocolates.end());

int start = 0,end = friends - 1,minDiff = chocolates[end] - chocolates[start];
while(end < boxes){
    minDiff = min(minDiff,chocolates[end++] - chocolates[start++]);
}

    cout << minDiff << endl;
}