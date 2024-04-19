#include "Date3.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int Date::get_year() const{
    int y = yyyymmdd[3] - '0' + (yyyymmdd[2] - '0') * 10 + (yyyymmdd[1]- '0') * 100 + (yyyymmdd[0] - '0') * 1000;   
    return y;
}
int Date::get_month() const{
    int m = yyyymmdd[5] - '0' + (yyyymmdd[4] - '0') * 10;
    return m;
}
int Date::get_day() const{
    int d = yyyymmdd[7] - '0' + (yyyymmdd[6] - '0') * 10;
    return d;
}
Date::Date(){
    yyyymmdd = "00010101";
}
bool valid(int year, int month, int day){
    int days[12] = {31,(year % 100 != 0 || year % 400 == 0) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    if(month > 12 || month <= 0) return false;
    if(day > days[month-1] || day <= 0) return false;
    if(year < 1 || year > 9999) return false;
    return true;
}
Date::Date(int year, int month, int day){
    if(!valid(year,month,day)){yyyymmdd = "00000000";return;}
    string temp = to_string(year); while(temp.size() < 4){temp = '0' + temp;}
    yyyymmdd = temp;
    temp = to_string(month); if(temp.size() < 2) temp = '0' + temp;
    yyyymmdd += temp;
    temp = to_string(day); if(temp.size() < 2) temp = '0' + temp;
    yyyymmdd += temp;
}

Date::Date(const string& year_month_day){
    istringstream st(year_month_day);
    int y; int m; int d;
    char s1; char s2;
    st >> y >> s1 >> m >> s2 >> d;
    if(s1 != '/' || s2 != '/' || !valid(y,m,d)){yyyymmdd = "00000000"; return;}
    string temp = to_string(y); while(temp.size() < 4){temp = '0' + temp;}
    yyyymmdd = temp;
    temp = to_string(m); if(temp.size() < 2) temp = '0' + temp;
    yyyymmdd += temp;
    temp = to_string(d); if(temp.size() < 2) temp = '0' + temp;
    yyyymmdd += temp;

    while(st >> s1) continue;
}

bool Date::is_valid() const{
    int y = (*this).get_year();
    int d = (*this).get_day();
    int m = (*this).get_month();
    if(y == 0 || m == 0 || d == 0|| !valid(y,m,d)) return false;
    return true;
}

int Date::num_days(int year, int month){
    int days[12] = {31,(year % 100 != 0 || year % 400 == 0) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    return days[month-1];
}
int main(){
    Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
    return 0;
}