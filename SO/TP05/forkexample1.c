#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
fork();
fork();
fork();
printf("%d\n",getpid());
exit(EXIT_SUCCESS);
}

// 8 processes are created
// 1 + 1 + 2 + 4 = 8