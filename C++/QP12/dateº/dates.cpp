#include <bits/stdc++.h> 
#include "Date.h"
using namespace std;

ostream& operator <<(ostream& os,const Date& dt){
    int y = dt.getYear();
    int m = dt.getMonth();
    int d = dt.getDay();
    string year = to_string(y);
    string month = to_string(m);
    string day = to_string(d);
    while(year.size() < 4) { year = '0' + year;}
    while(month.size() < 2) { month = '0' + month;}
    while(day.size() < 2) { day = '0' + day;}
    os << year << '/' << month << '/' << day;
    return os;
}

bool operator <(Date a, Date b){
    if(a.getYear() < b.getYear()) return true;
    else if (a.getYear() == b.getYear() && a.getMonth() < b.getMonth()) return true;
    else if (a.getYear() == b.getYear() && a.getMonth() == b.getMonth() && a.getDay() < b.getDay()) return true;
    return false;
}