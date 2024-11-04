#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int lines = 0, words = 0, chars = 0;
    int nlines = 0, nwords = 0, nchars = 0;
    int c, flag = 1;
    for(int i = 1; i < argc; i++){
        if(argv[i][0] == '-'){
            for(int j = 1; argv[i][j] != '\0'; j++){
                switch (argv[i][j]){
                case 'c' :chars = 1; break;
                case 'w' : words = 1; break;
                case 'l' : lines = 1; break;
                
                default: printf("Invalid argument"); break; exit(EXIT_FAILURE);
                
                } 
            }
        }
    }
    for(int i = 1; i < argc; i++){
        if(argv[i][0] != '-'){
            FILE* file = fopen(argv[i], "r");
            while((c = fgetc(file)) != EOF){
                switch (c){
                    case '\n' : nlines++;
                    case '\t' :
                    case ' '  : 
                        if(!flag){
                            flag = 1;
                            nwords++;
                        }
                            nchars++;
                            break;
                    default   : nchars++; flag = 0; 
                }
            }
        if(!flag) nwords++;
        if(lines) printf("%d\t",nlines);
        if(words) printf("%d\t",nwords);
        if(chars) printf("%d\t",nchars);
        printf("%s\n",argv[i]);
        nchars = 0; nwords = 0; nlines = 0;
        fclose(file);
        }
    }
}