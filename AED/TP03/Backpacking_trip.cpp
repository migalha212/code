#include <iostream>
#include <vector>
using namespace std;

bool isPossible(const vector<int> & v, int x, int k);
int distanceconst(vector<int> & v, int k);

int main(){
    vector<int> v;
    int x,k,n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        cout << distanceconst(v,k) << endl;
    }
}

bool isPossible(const vector<int> &v, int x, int k)
{
    int curr_sum = 0;
    int count = 1;

    for(int i = 0; i < int(v.size()); i++){
        if(v[i] > x){
            return false;
        }
        curr_sum += v[i];
        if(curr_sum > x ){
            count++;
            curr_sum = v[i];
        }
        if(count > k){
            return false;
        }
    } 
    return true;
}

int distanceconst(vector<int> &v, int k)
{
    int res = 1;
    while(!isPossible(v,res,k)){
        res++;
    }
    return res;
}
