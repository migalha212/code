#include "Point2d.h"
#include <iostream>
#include <math.h>
using namespace std;

void Point2d::translate(const Point2d &t){
    this->x = x + t.x;
     this->y = y + t.y;
}
double Point2d::distance_to(const Point2d& p) const{
    return sqrt(((x - p.x) * (x - p.x)) + ((y - p.y) * (y-p.y)));
}

int main(){

    return 0;
}