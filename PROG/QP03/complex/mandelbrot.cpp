#include <iostream>
#include "complex.h"
using namespace std;

void mul(const complex& a, const complex& b, complex& r){
    r.x = -(a.y * b.y) + a.x * b.x;
    r.y = a.x*b.y + b.x*a.y;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    if(n == 0){
        z_n.x = 0;
        z_n.y = 0;
    }
    else{
        
        mandelbrot(c,n-1,z_n);
        complex aux =  z_n;
        mul(z_n,z_n,aux);
        z_n.x = aux.x+ c.x;
        z_n.y = aux.y+ c.y;
    }
}
complex operator+(complex a,complex b){
    return complex{a.x + b.x,a.y+b.y};
}

int main(){
    { complex z_n;
    mandelbrot({1,1}, 1, z_n);
    cout << z_n << '\n'; }
    { complex z_n;
    mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n'; }
    complex a = {1,1}, b = {1,1};
    cout << a + b;
    return 0;
}
