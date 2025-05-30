#include "Date.h"

Date::Date(){
    year_ = month_ = day_ = 1;
}

Date::Date(int year, int month, int day){
    this->year_ = year;
    this->month_ = month;
    this->day_ = day;
}

bool Date::is_before(const Date& date) const{
    if(this->year_ < date.year_) return true;
    else if(this->year_ == date.year_ && this->month_ < date.month_ ) return true;
    else if(this->year_ == date.year_ && this->month_ == date.month_ && this->day_ < date.day_) return true;
    return false;
}

