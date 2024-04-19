#include <iostream>
#include "interval.h"
using namespace std;
bool operator>=(const time_of_day &a,const time_of_day &b){
    if((a.h > b.h) || (a.h == b.h && a.m >= b.m)) return true;
    return false;
}
bool operator<(const time_of_day a,const time_of_day b){
    if((a.h < b.h) || (a.h == b.h && a.m < b.m)) return true;
    return false;
}
int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    u = {t,t};
    for(int i = 0;i< n;i++){
        if(t >= a[i].start  && t < a[i].end){
            u.start = u.start >= a[i].start ? a[i].start : u.start;
            u.end = u.end < a[i].end ? a[i].end : u.end;
        }
    }

    return ((u.end.h - u.start.h) * 60) + (u.end.m - u.start.m);
}

int main(){
  { const int n = 1;
  const time_of_day t = { 13, 00 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }
    return 0;
}
