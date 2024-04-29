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

    double perimeter() const;
    void add_vertex(int index,Point point);
    bool get_vertex(size_t index, Point &point);
    void show() const;

private:
    std::vector<Point> points;
};

#endif