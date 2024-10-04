#include <iostream>
#include <vector>
using namespace std;

int MaxSum(vector<int> &vec);

int main(){
    vector<int> vec;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int p; cin >> p;
        vec.push_back(p);
    }
    cout << MaxSum(vec) << endl;
    return 0;
}

int MaxSum(vector<int> &vec){
    int best_sum = vec[0];
    int curr_sum = 0;

    for(int i : vec){
        curr_sum = max(i, curr_sum + i);
        best_sum = max(curr_sum,best_sum);
    }
    return best_sum;
}