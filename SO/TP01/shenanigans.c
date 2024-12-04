#include <stdio.h>
#include <stdlib.h>

int g(int (*h)(char,int),int y){
    return h('A',2);
}

int f(char x, int y){return x + y;}

int main(){
    int y = 2;
    printf("%c",g(f,y));
    return 0;
}