#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 64

int main(int argc, char* argv[]){
    char* p1 = (char*)malloc(MAX_SIZE * sizeof(char));
    printf("%s \n",argv[1]);
    strcpy(p1,argv[1]);
    for (int i = 0; p1[i] != 0; i++){
        p1[i] = tolower(p1[i]);
    } 
    printf("%s",p1);
    exit(0);
}