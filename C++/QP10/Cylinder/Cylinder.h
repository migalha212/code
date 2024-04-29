#ifndef CYLINDER_H
#define CYLINDER_H

#include "Solid.h"

class Cylinder : public Solid{
private:
    double radius_;
    double height_;
public:
    Cylinder(point center, double radius, double height) : Solid(center), radius_(radius), height_(height) {}
    double radius() const {return radius_;}
    double height() const {return height_;}
    double area() const {
        return 2.0 * M_PI * radius_ * (radius_ + height_);
    }
};
#endif