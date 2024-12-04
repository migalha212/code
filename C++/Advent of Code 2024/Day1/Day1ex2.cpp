#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    // set-up
    map<long,pair<long,long>> similarity;
    vector<long> list2;
    long i= 1,j = 1;
    while(i && j ){
        cin >> i >> j;
        if(similarity.find(i) != similarity.end()){
            similarity[i].second++;
        }
        else{
            similarity[i] = {0,1};
        }
        list2.push_back(j);
    }

    // solution
    long long res = 0;
    for(size_t i = 0; i < list2.size(); i++){
        if(similarity.find(list2[i]) != similarity.end()){
            similarity[list2[i]].first++;
        }
    }
    for(pair<long,pair<long,long>> similarities : similarity){
        res += similarities.first * similarities.second.second * similarities.second.first;
    }
    cout << res;
}