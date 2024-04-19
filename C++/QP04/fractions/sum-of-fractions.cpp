#include <iostream>
#include "fraction.h"
using namespace std;

int gcd(fraction a){
    if (a.den == 0) return a.num;
    return gcd({a.den,a.num % a.den});
}

fraction simple(fraction a){

    int gvd = gcd(a);
    if (gvd == 1) return a;
    else {
        a.num = a.num / gvd;
        a.den = a.den / gvd;
    }
    if(a.den < 0){
        a.den = -a.den;
        a.num = -a.num;
    }
    return a;
}
fraction operator +(fraction a, fraction b){
    fraction result = {0,0};
    if (a.den == b.den) result = {a.num+b.num,b.den};
    else{
        result = {a.num * b.den + b.num*a.den,b.den * a.den};
    }
    return simple(result);
}
fraction sum(const fraction fa[], int n){
    fraction f1 = fa[0];
    if(n == 1) return f1;
    fraction f2;
    for(int i = 1; i < n; i++){
        f2 = fa[i];
        f1 = simple(f1+f2);
    }
    return f1;
}


int main(){
    { const int n = 2;
  const fraction fa[n] { {1, 2}, {-1, 3} };
  cout << sum(fa, n) << '\n'; }
    return 0;
}