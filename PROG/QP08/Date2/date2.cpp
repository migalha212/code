#include "Date2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Date::Date(){
 year = 1;
 month = 1;
 day = 1;
}
bool valid(int year, int month, int day){
    int days[12] = {31,(year % 100 != 0 || year % 400 == 0) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    if(month > 12) return false;
    if(day > days[month-1] || day <= 0) return false;
    if(year < 1 || year > 9999) return false;
    return true;
}
Date::Date(int year, int month, int day){
    if(!valid(year,month,day)){
        this->day = this->month = this->year = 0;
        return;
    }
    this->year = year;
    this->month = month;
    this->day = day;

}

Date::Date(const string& year_month_day){
    istringstream st(year_month_day);
    int y; int m; int d;
    char s1; char s2;
    st >> y >> s1 >> m >> s2 >> d;
    if(s1 != '/' || s2 != '/' || !valid(y,m,d)){year = month = day = 0; return;}
    year = y; month = m; day = d;
    while(st >> s1) continue;
}

bool Date::is_valid() const{
    if(month == 0 || year == 0 || day == 0) return false;
    return true;
}

int main(){
    Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
    Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;
    return 0;
}