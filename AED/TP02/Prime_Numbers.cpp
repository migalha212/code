#include <iostream>
#include <cmath>
using namespace std;


int main(){
    bool r = 0;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int n; 
        cin >> n;
        for(int j = 2; j <= sqrt(n); j++){
            if(n % j == 0){
                cout << n << " is composite" << endl;
                r = 1;
                break;
            }
        }
            if(!r){
            cout << n << " is prime" << endl;
            }
            r = 0;
    }

    return 0;
}