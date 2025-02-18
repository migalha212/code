#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int children, maxWeight;
    cin >> children >> maxWeight;
    vector<int> v(children);
    for(int i = 0; i < children; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int cabins = 0, f = children - 1, i = 0;
    while(f >= i){
        if(v[i] + v[f] <= maxWeight){
            cabins++; 
            i++; f--; 
        }
        else{
            cabins++;
            f--;
        }
    }
    cout << cabins << endl;
return 0;
}