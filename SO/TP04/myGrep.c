#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER 5
char * lineGet(FILE*);

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Invalid argument number");
        exit(EXIT_FAILURE);
    }
    FILE* file = fopen(argv[2],"r");
    char * line;
    while((line = lineGet(file))){
        printf("%s",line);
    }
    
    
}


char * lineGet(FILE* file){          //*     l1 receives #buffer characters
    char * line = (char*)malloc(BUFFER * sizeof(char));
    char *line2 = (char*)malloc(BUFFER * sizeof(char));
    int buffer = 0;
    int counter = 0;
    line[0] = '\0';
    line2[0] = '\0';    
    

    while(fgets(line ,BUFFER,file) != NULL){

        if( strlen(line) == BUFFER - 1 && line[BUFFER - 2] != '\n'){
            strcpy(line2 + buffer - counter++,line);
            char * line3 = line2;
            buffer += BUFFER;
            line2 = (char*)malloc((buffer + BUFFER) * sizeof(char));
            strcpy(line2,line3);
            free(line3);
        }
        else{  
            strcpy(line2 + buffer - counter,line); 
            break;
        }
    }
    free(line);
    return line2[0] == '\0' ? NULL : line2;

}