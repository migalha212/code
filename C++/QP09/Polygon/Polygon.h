#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include <vector>
#include <math.h>

double distance(const Point p1,const Point p2);

class Polygon{
public:
    Polygon();
    Polygon(std::vector<Point> vertices);

    double perimiter() const;
    void add_vertex(int index,Point point);
    bool get_vertex(int index, Point point) const;
    void show() const;

private:
    std::vector<Point> points;
};

#endif