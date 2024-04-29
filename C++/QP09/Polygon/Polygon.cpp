#include "Polygon.h"

Polygon::Polygon(){
    points = {};
}

Polygon::Polygon(std::vector<Point> vertices){
    for(Point p : vertices){
        points.push_back(p);
    }
}
double distance(const Point p1, const Point p2){
    return sqrt((pow(p2.get_x() - p1.get_x(),2))+ (pow(p2.get_y() - p1.get_y(),2)));
}
double Polygon::perimeter() const{
    if(points.size() <= 1){return 0;}
    Point p1 = points[0];
    double pem = 0;
    for(Point p2 : points){
        pem += distance(p1,p2);
        p1 = p2;
        
    }
    pem += distance(p1,points[0]);
    return pem;
}

void Polygon::add_vertex(int index,Point point){
    points.insert(points.begin() + index-1, point);
}

bool Polygon::get_vertex(size_t index, Point& point){
    if(index > points.size() || index <= 0) return false;
    point = points[index - 1]; return true; 
}

void Polygon::show() const{
    std::cout << '{';
    for(Point p: points){
        p.show();
    }
    std::cout << '}';
}