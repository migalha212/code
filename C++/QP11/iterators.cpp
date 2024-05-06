#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
using namespace std;


template <typename Itr> 
string to_string(Itr start, Itr end){
    ostringstream os;
    os << "[ ";
    while (start != end){
        os << *start << ' ';
        start++;
    }
    os << ']';
    return os.str();
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b){
    int count = 0;
    while(start != end){
        if(*start == a){
            *start = b; count++;
        }
    start++;
    }
    return count;
}


int main(){
    { list<string> l { "C++", "Java", "C++", "Python", "Rust", "C" } ;
  cout << replace(l.begin(), l.end(), string("C++"), string("Rust")) << ' '
       << replace(l.begin(), l.end(), string("C"), string("Rust")) << ' '
       << to_string(l.cbegin(), l.cend()) << '\n'; }

       return 0;
}