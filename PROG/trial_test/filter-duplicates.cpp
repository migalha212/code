#include <iostream>
#include "print_array.h"
using namespace std;

int filter_duplicates(const int a[], int n, int b[]){
    int flag = 0;
    int last = 0;
    for(int i = 0; i < n; i++){
        if (flag){
            if(a[i] == last) continue;
        }
        last = a[i];
        b[flag] = a[i]; flag++;
    }
    return flag;
}