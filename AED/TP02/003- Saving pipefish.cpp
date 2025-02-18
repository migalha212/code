#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,k,t;
    vector<int> vec;
    cin >> n >> k >> t;
    int curr = 0; int res = 0;
    for(int i = 0; i < n; i++){
        
        if(i > k -1){
            curr += vec[i-k];
        }

        int input; cin >> input;

        if(input >= t){ 
            curr++;
            vec.push_back(-1);
        }
        else vec.push_back(0);

        if(curr >= (k % 2 == 0 ? k/2 : k/2 +1) && i >= k-1) res++;
    }

    cout << res << endl;
    return 0;
}