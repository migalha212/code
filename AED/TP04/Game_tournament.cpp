#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline bool big(int a, int b){
    return a > b;
}
int main(){
    int n, k, x;
    vector<int> v;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(), big);

    for(int i = 0; i < k; i++){
        cout << v[i] << endl;
    }
}