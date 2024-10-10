#include <iostream>
using namespace std;
int aux(const char arr[]){
    int i = 0;
    while(arr[i]){
        i++;
    }
    return i;
}
const char* longest(const char* pa[]){
    int res = 0;
    for(int i = 0; pa[i]; i++){
        if(aux(pa[i]) >= aux(pa[res])){
            res = i;
        }
    }
    return pa[res];
}