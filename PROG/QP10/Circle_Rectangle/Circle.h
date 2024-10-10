#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

double aux(point a, point b){
    double dis = sqrt(pow(a.x-b.x,2) + pow(a.y - b.y,2));
    return dis;
}
class Circle : public Shape{
private:
    double radius_;
public:
    Circle(point center, double radius) : Shape(center), radius_(radius) {}
    double area() const{
        return radius_ * radius_ * M_PI;
    }
    double perimeter() const{
        return 2.0 * radius_ * M_PI;
    }
    bool contains(const point& p) const{
        if(aux(p,get_center()) > radius_) return false;
        return true;
    }
};

#endif