#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void closest(vector<int> &v, int x);

int main(){
    vector<int> v1,v2;
    int n,x; cin >> n;
    for(int i = 0; i< n; i++){
        cin >> x;
        v1.push_back(x);
    }
    cin >> n;
    for(int i = 0; i < int(v1.size()) - 1; i++){
        for(int j = i+1; j < int(v1.size()); j++){
            v2.push_back(v1[i] + v1[j]);
        }
    }
    sort(v2.begin(),v2.end());
    for(int i = 0; i < n; i++){
        cin >> x;
        closest(v2,x);
    }

}       
//*  53  [13,25,34,43,52,62,72]
void closest(vector<int> &v, int x){
    int x1 = 0,x2 = 0;
    int low = 0;int hi = v.size() - 1;
    int res = 0;
    while(low < hi){
        int mid = low + (hi - low) / 2;
        if(v[mid] < x){
            low = mid + 1;
        }
        else if(v[mid] > x){
            hi = mid;
        }
        else{
            res = mid;
            break;
        }
    }
    if(x <= v[low]){
        res = low;
        if(!res){
            cout << v[res] << endl;
            return;
        }
    }
    if(x > v[hi]){
        res = hi;
    }
    x1 = v[res - 1]; x2 = v[res];
    if(x - x1 == x2 - x && x1 != x2){
        cout << x1 << ' ' << x2 << endl;
    }
    else
        cout << ((x-x1 < x2 - x) ? x1 : x2) << endl;
}
