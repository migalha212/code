#include <iostream>
#include <vector>
using namespace std;

int count(vector<int>& vec, int f, int c){
    int low = 0; int hi = (int)vec.size() -1;
    int flo = -1; int ceil = -1;
        while(low < hi){
            int middle = low + (hi - low)/2;
            if(f > vec[middle]){
                low = middle + 1;
            }
            else if(f <= vec[middle]){
                hi = middle;
            }
            else{
                flo = middle;
                break;
            }
        }
        if(f <= vec[low]){
            flo = low;
        }
    low = flo; hi = (int)vec.size() -1;
        while(low <= hi){
            int middle = low + (hi - low)/2;
            if(c >= vec[middle]){
                low = middle+1;
            }
            else if(c < vec[middle]){
                hi = middle - 1;
            }
            else {
                ceil = middle; break;
            }
        }
        if(c >= vec[hi]){
            ceil = hi;
        }

        if(flo == -1 || ceil == -1){
            return 0;
        }

    return ceil - flo + 1;
}

int main(){
    int n,x,q; 
    cin >> n;
    vector<int> vec;
    for(int i = 0; i < n; i++){
        cin >> x;
        vec.push_back(x);
    }
    cin >> q;
    int f,c;
    for(int i = 0; i < q; i++){
        cin >> f >> c;
        cout << count(vec,f,c) << endl;
    }
    return 0;
}