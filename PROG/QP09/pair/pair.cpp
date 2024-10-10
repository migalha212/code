#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename one,typename two>

class Pair{
private:
 one first_;
 two second_;
public:
    Pair(one f,two s){
        first_ = f; second_ = s;
    }
    one get_first() const{
        return first_;
    }
    two get_second() const{
        return second_;
    }
    void show() const{
        cout << '{';
        cout << first_;
        cout << ',';
        cout << second_;
        cout << '}';
    }
};

bool aux1(Pair<string,int> p1, Pair<string,int> p2){
    if(p1.get_first() < p2.get_first()) return true;
    else if(p1.get_first() == p2.get_first() && p1.get_second() < p2.get_second()) return true;
    return false;
}
void sort_by_first(vector <Pair<string,int>> &vec){
 sort(vec.begin(),vec.end(),aux1);
}
bool aux2(Pair<string,int> p1, Pair<string,int> p2){
    if(p1.get_second() < p2.get_second()) return true;
    else if(p1.get_second() == p2.get_second() && p1.get_first() < p2.get_first()) return true;
    return false;
}

void sort_by_second(vector <Pair<string,int>> &vec){
sort(vec.begin(),vec.end(),aux2);
}

void show(vector <Pair<string,int>> vec){
    cout << '{';
    for (Pair<string,int> p : vec){
        p.show();
    }
    cout << '}';
}


int main(){
    Pair<int,int> p = Pair<int,int>(1,2); 
}