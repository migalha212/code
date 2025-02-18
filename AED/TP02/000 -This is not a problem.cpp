#include <iostream>
using namespace std;

int main(){
    int q = 0;
    int res = 0;
    int input = 0;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> input;
        if(input == 42) res++;
    }
    cout << res << endl;
    return 0;
}
