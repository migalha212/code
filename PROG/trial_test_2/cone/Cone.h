#include "Solid3D.h"
#include <cmath>


class Cone : public Solid3D{
public:
    Cone(const point &center, double radius, double height) : Solid3D(center),radius_(radius),height_(height){}
    double height() const {return height_;}
    double radius() const {return radius_;}
    double volume() const override {return (M_PI * radius_ * radius_ * height_) / 3.0;}

private:
    double radius_,height_;
};