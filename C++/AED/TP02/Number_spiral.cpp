#include <iostream>
#include <cmath>
using namespace std;


void spiral(long long n){
    if(n == 1)
        cout << "(0,0)" << endl;
    int x = 0; int y = 0;
    long long int root = ceil(sqrt(n));
    long long int q = root * root;

// (x,y) = (3+(x-1*2)) ** 2  (1,1) = 9; (2,2) = 25; (3,3) = 49
// (x,y) = (
    if(root % 2 == 0){
        x = 1 - (root / 2 ); 
        y = 0 - (root / 2 );
        for(int i = 1; i < root; i++){
            if(q != n){ q--; x++;}
            else {break;}
        }
        for(int i = 1; i < root; i++){
            if(q != n){ q--; y++;}
            else {break;}
        }
    }
    else{
        x = 1 + ((root - 1) / 2 - 1);
        y = 1 + ((root- 1 ) / 2 - 1);
        for(int i = 1; i < root; i++){
            if(q != n){ q--; x--;}
            else {break;}
        }
        for(int i = 1; i < root; i++){
            if(q != n){ q--; y--;}
            else {break;}
        }
    }


    cout << '(' << x << ',' << y << ')' << endl;
}

int main(){
    long long n;
    cin >> n;
    spiral (n);
}