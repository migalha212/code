#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv []) {
    for (int i = 0; i < 4; i++)
        fork();

    printf("%d\n", getpid());
    exit(EXIT_SUCCESS);
}


// 16 processes are created
// 1 + 1 + 2 + 4 + 8 = 16