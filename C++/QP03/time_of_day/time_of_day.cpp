#include <iostream>
#include "time_of_day.h"
using namespace std;

time_of_day tick(time_of_day t){
    t.m++;
    if(t.m >= 60){
        t.m -= 60;
        t.h += 1;
    }
    if(t.h >= 24) t.h -= 24;
    return t;
}

int main(){
    cout << tick({ 0, 0 }) << '\n';
    return 0;
}