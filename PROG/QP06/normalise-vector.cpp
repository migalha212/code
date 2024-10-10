#include <iostream>
#include "print_vector.h"
#include <string>
using namespace std;


 template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){
    for(long unsigned int i = 0; i < v.size(); i++){
        if(v[i] < min) v[i] = min;
        else if(v[i] > max) v[i] = max;
    }
}