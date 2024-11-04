#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char *a = "am\n";
    char *b = "mama";
    char *c = (char*)malloc(8 * sizeof(char));
    strcpy(c,b);
    printf("%s",c);
    strcpy(c+4,a);
    printf("\n%s",c);
}