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
double Polygon::perimiter() const{

}

void Polygon::add_vertex(int index,Point point){
    points.insert(points.begin() + index-1, point);
}

bool Polygon::get_vertex(int index, Point point) const{
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