#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    // set-up
    vector<long> list1;
    vector<long> list2;
    long i,j;
    while(i != 0 && j != 0){
        cin >> i >> j;
        list1.push_back(i);
        list2.push_back(j);
    }
    sort(list1.begin(),list1.end());
    sort(list2.begin(),list2.end());

    // solution
    long long res = 0;
    for(size_t i = 0; i < list1.size(); i++){
        res += abs(list1[i] - list2[i]);
    }
    cout << res;
}