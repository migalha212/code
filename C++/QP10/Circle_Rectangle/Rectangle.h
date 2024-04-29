#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <cmath>

double dabs(double a){
    return a < 0 ? -a : a;
}
class Rectangle : public Shape{
private:
    double width_,height_;
public:
    Rectangle(point center, double width, double height) : Shape(center), width_(width), height_(height) {}
    double area() const{
        return width_ * height_;
    }
    double perimeter() const{
        return width_ * 2.0 + height_ * 2.0;
    }
    bool contains(const point& p) const{
        if(dabs(p.x - get_center().x) <= width_ / 2.0 && dabs(p.y - get_center().y) <= height_ / 2.0) return true;
        return false;
    }
};

#endif