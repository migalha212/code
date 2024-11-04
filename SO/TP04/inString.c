#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 64

int main(int argc, char* argv[]) {
    if(argc != 3){
        printf("only 2 input can be taken");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    char* hay = argv[2];
    char* pos = strstr(hay,argv[1]);
    while(pos != NULL){
        count++;
        pos = strstr(pos + 1, argv[1]);
    }
    printf("found \"%s\" %i times",argv[1],count);
    exit(0);
} 