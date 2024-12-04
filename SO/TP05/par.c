#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv []) {
    char* comp[6];
    comp[0] = "gcc"; 
    comp[2] = "-o";
    comp[4] = "-Wall"; 
    comp[5] = NULL;
    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            comp[1] = argv[i];
            char* out = malloc(strlen(argv[i]) + 3);
            out = strcpy(out, argv[i]);
            comp[3] = strsep(&out, ".");
            printf("[pid:%d]: compiling %s ...\n", getpid(), argv[i]);
            execvp(comp[0], comp);
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 1; i < argc; i++)
        wait(NULL);
    exit(EXIT_SUCCESS);
}