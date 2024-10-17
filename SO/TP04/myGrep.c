#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER 5
char * lineGet(FILE*);

int main(int argc, char* argv[]){
    char * s = lineGet(stdin);
    printf("%s",s); exit(EXIT_FAILURE);
    if(argc != 3){
        printf("Invalid argument number");
        exit(EXIT_FAILURE);
    }
    FILE* file = fopen(argv[2],"r");

    
}


char * lineGet(FILE* file){
    char * line = (char*)malloc(BUFFER * sizeof(char));
    line[0] = 0;
    while(fgets(line + strlen(line),BUFFER,file) != NULL){
        if( strlen(line) == BUFFER - 1 && line[BUFFER - 1] != '\n'){
            char * line2 = line;
            char * line = (char*)malloc((strlen(line2) + BUFFER)  * sizeof(char));
            strcpy(line,line2);
            free(line2);
        }
        else{
            break;
        }
        
    }
    return line;

    
}