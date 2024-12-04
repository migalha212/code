#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]){
    FILE* file = fopen(argv[1],"r");
    FILE* file2 = fopen(argv[2],"w");

    char buffer[BUFFER_SIZE];
    int nchars ;
        while((nchars = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0){
            fwrite(buffer, sizeof(char), nchars, file2);
        }
        fclose(file);
        fclose(file2);
    exit(EXIT_SUCCESS);
}