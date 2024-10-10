#ifndef POINT_H
#define POINT_H

#include <iostream>
class Point{
public:
    Point(); // (0,0)
    Point(int x, int y);

    int get_x() const;
    int get_y() const;
    void show() const;
    
private:
    int x_;
    int y_;

};

#endif