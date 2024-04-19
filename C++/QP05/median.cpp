#include <iostream>
#include <algorithm>
using namespace std;

int median(const int a[], int n){
    int *temp = new int[n];
    for(int i = 0; i < n; i++){temp[i] = a[i];}
    sort(temp, temp+n);
    int med;
    if(n % 2 == 1){
      med = temp[n/2];
    }
    else {
      med = ((temp[n/2-1] + temp[n/2]) / 2);
    }
    delete []temp;
    return med;
}

int main(){
{ const int n = 5; 
  int a[n] { 10, -10, 0, 12, 11 };
  cout << median(a, n) << '\n'; }
  return 0;
}

