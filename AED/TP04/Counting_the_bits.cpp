#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct 
{
    int x;
    int s1;
} bits;

inline bool big(bits a, bits b){
    if(a.s1 < b.s1){ return false;}
    else if (a.s1 == b.s1) return a.x < b.x;
    return true;
}

inline int bit(int x){
    int c = 0;
    while(x > 1){
        if (x%2 == 1) c++;
        x /= 2;
        }
    return c;
}

int main(){
    int n,x;
    cin >> n;
    vector<bits> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].x; v[i].s1 = bit(v[i].x);
    }
    sort(v.begin(),v.end(),big);
    for(bits b: v){
        cout << b.x << endl;
    }
}