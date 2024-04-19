#include <iostream>
#include "complex.h"
using namespace std;

complex operator+(complex a, complex b){
    complex c = {0,0};
    c.real = a.real + b.real;
    c.img =  a.img + b.img;
    return c;
}
complex operator*(complex a, complex b){
    complex c = {0,0};
    c.real = a.real*b.real - b.img*a.img;
    c.img = a.real*b.img + a.img * b.real;
    return c;
}
void mandel(complex c, int n, complex z[]){;
    z[0] = {0,0};
    for(int i = 1; i < n; i++){
        z[i] = ((z[i - 1] * z[i - 1]) + c);
    }
}

int main(){
{ complex c = { 0, 3 };
  const int n = 5;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
    return 0;
}