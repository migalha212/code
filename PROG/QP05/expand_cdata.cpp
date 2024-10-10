#include <iostream>
#include "cdata.h"
using namespace std;

int* expand_cdata(const cdata a[], int n){
    int tam = 0;
    for(int i = 0; i < n; i++){
        tam += a[i].count;
    }
    int *res= new int[tam+1];
    int pos = 0;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < a[i].count;j++){
            res[pos] = a[i].value;
            pos++;
        }
    }
    res[pos] = 0;
    return res;
}


int main(){
{ const int n = 1;
  const cdata a[] { { 3, 999 } };
  int* r = expand_cdata(a, n);
  print_array(r, 3);
  delete [] r; }
{ const int n = 3;
  const cdata a[] { { 3, 100 }, { 2, 200 }, { 1, 300 } };
  int* r = expand_cdata(a, n);
  print_array(r, 6);
  delete [] r; } 
  return 0;
}