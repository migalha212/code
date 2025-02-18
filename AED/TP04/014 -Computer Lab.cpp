#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, count = 0; cin >> n;
    int maximum = 0;
    vector<int> entries(n);
    vector<int> leafs(n);

    for(int i = 0; i < n; i++){
        cin >> entries[i] >> leafs[i];
    }
    
    sort(entries.begin(),entries.end());
    sort(leafs.begin(),leafs.end());

    int entry = 0, leave = 0, i = 0;
    while(entry < int(entries.size()) || leave < int(leafs.size())){
        if(entries[entry] == i && entry < entries.size()) {count++; entry++;}
        if(leafs[leave] == i && leave < leafs.size()) {count--; leave++;}
        if(entry < entries.size() && leave < leafs.size()) i = min(entries[entry],leafs[leave]);
        else if(entry < entries.size()) i = entries[entry];
        else i = leafs[leave];
        maximum = max(maximum,count);
    }

cout << maximum << endl;
}
