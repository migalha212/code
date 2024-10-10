#include <iostream>
using namespace std;

int max(const int a[], int n){
    int res = a[0];
    while(n-1){
        if(a[n-1] > res) res = a[n-1];
        n--;
    }
    return res;
}