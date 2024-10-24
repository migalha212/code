#include <vector>
#include <iostream>
using namespace std;

int numberSearch(vector<int>& v, int k){
    int res = -1;
    int low = 0, high = v.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(v[mid] < k){
            low = mid + 1;
        }
        else if(v[mid] > k){
            high = mid - 1;
        }
        else{
            res = mid; break;
        }
    }
    return res;
}

int lowerBound(vector<int>& v, int k){
    int res = -1;
    int low = 0, high = v.size() - 1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(v[mid] < k){
            low = mid + 1;
        } // [2 2 2 3 5 5 8 8 8 8]
        else if(v[mid] >= k){
            high = mid;
        }
    }
    if (k <= v[low]){
        res = low;
    }
    return res;
}

int intervalCount(vector<int> &v, const int lo, const int hi){
    int low = 0, high = v.size() - 1;

    int lbound = -1;
    while(low < high){
        int mid = low + (high - low) / 2;
        if(v[mid] < lo) low = mid + 1;
        else if( v[mid] >= lo) high = mid;
    }
        if(lo <= v[low]) lbound = low;
    
    low = 0; high = v.size()- 1;
    int hbound = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(v[mid] <= hi) low = mid + 1;
        else if(v[mid] > hi) high = mid - 1;

    }
        if(hi >= v[high]) hbound = high;


    if(lbound == -1) lbound = v.size();
    return hbound - lbound + 1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> n;
    int k,j;
    for(int i = 0; i < n; i++){
        cin >> k >> j;
        cout << intervalCount(v,k,j) << endl;
    }
}
