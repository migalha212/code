#include <iostream>
#include <vector>
using namespace std;

int lowerbound(vector<int> & vec, int x){   //TODO: remake code to be correct
    int lower = 0; int higher = (int)vec.size() - 1;
    int res = -1;
    while(lower <= higher){
        int middle = lower + (higher - lower)/ 2;
        if(x <=vec[middle]){
            higher = middle;
        }
        else if(x > vec[middle]){
            lower = middle + 1;
        }
        else{
            res = middle;
            break;
        }
        if(vec[lower] >= x){
            return lower;
        }
        else return -1;
    }


    return res;
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
    for(int i = 0; i < q; i++){
        cin >> x;
        cout << lowerbound(vec,x) << endl;
    }
    return 0;
}