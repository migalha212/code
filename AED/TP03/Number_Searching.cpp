#include <iostream>
#include <vector>
using namespace std;

int query(int x, vector<int>& vec);


int main(){
    int n,x,q; 
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        cin >> x;
        vec.push_back(x);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> x;
        cout << query(x,vec) << endl;
    }
    return 0;
}

int query(int x, vector<int>& vec){
    int res = -1;
    int low = 0; int high = (int)vec.size() -1;
    while(low <= high){
    //if(vec[low] > x || vec[high] < x) break;
        int middle = low + (high - low)/ 2;
        if(x < vec[middle]){
            high = middle - 1;
        }
        else if(x > vec[middle]){
            low = middle + 1;
        }
        else{
            res = middle;
            return middle;
        }
    }

    return res;
}

