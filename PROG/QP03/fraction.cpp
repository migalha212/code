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
fraction add(fraction a, fraction b){
    fraction result = {0,0};
    if (a.den == b.den) result = {a.num+b.num,b.den};
    else{
        result = {a.num * b.den + b.num*a.den,b.den * a.den};
    }
    return simple(result);
}

fraction mul(fraction a, fraction b){
    fraction result = {0,0};
    result = {a.num * b.num,a.den * b.den};
    return simple(result);
}

int main(){
    { fraction a { 0, 1 }, b { 2, 1};
    cout << add(a,b) << ' ' << mul(a,b) << '\n'; }
    return 0;
}

