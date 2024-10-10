#include "Point.h"

Point::Point(){
    x_ = y_ = 0;
}
Point::Point(int x, int y){
    x_ = x; y_ = y;
}

int Point::get_x() const{
    return x_;
}
int Point::get_y() const{
    return y_;
}

void Point::show() const{
    std::cout << '(' << x_ << ',' << y_ << ')';
}