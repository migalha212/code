#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef struct{
    double x;
    double y;
}Point;

bool slopeComp(Point a, Point b){
    return (a.y / a.x) < (b.y/b.x);
}

void convexHull(vector<Point> &v);

int main(){
    //* setup
    int n;
    cin >> n;
    vector<Point> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y;
    }

    convexHull(v);
}
/// @brief at
/// @param v 
void convexHull(vector<Point> &v){
    int pc = 0;
    Point lowest = {INT_MAX,INT_MAX};
    //* compute the Point with the lowest y, or in case of repitition, lowest x;
    for(Point p : v){
        if(p.y < lowest.y) lowest = p;
        else if(p.y == lowest.y && p.x < lowest.x) lowest = p;
    }

//* sort the points in ascending order of angle with the x axis;
    sort(v.begin(),v.end(),slopeComp);
    
    cout << pc << endl;
    for(Point p : v){
        cout << p.x << ' ' << p.y << ' ' << p.y / p.x << endl;
    }

}