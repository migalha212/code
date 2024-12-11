#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define LINESIZE 256
int main(int argc, char* argv []) {
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1) { perror("pipe"); exit(EXIT_FAILURE); }
    if ((pid = fork()) == -1) { perror("fork"); exit(EXIT_FAILURE); }
    if (pid > 0) { /* parent */
        if (argc <= 1) { perror("No File Argument was given"); exit(EXIT_FAILURE); }
        char line[LINESIZE];
        strcpy(line, argv[1]);
        close(fd[0]); // closes out the option for the parent to read the "File"
        write(fd[1], line, strlen(line)); // does his part of writing
        close(fd[1]);
        if (wait(NULL) == -1) { perror("wait"); exit(EXIT_FAILURE); }
        exit(EXIT_SUCCESS);
    }
    else { /* child */
        char line[LINESIZE];
        close(fd[1]); // closes out the option for the child to write to the "File"
        int nbytes = read(fd[0], line, LINESIZE); // does his part and reads 
        int file = open(line, O_RDONLY);
        if (file < 0) { perror("Invalid File Path"); exit(EXIT_FAILURE); }
        char text[LINESIZE];
        int filebytes;
        while (filebytes = read(file, text, LINESIZE)) {
            write(STDOUT_FILENO, text, filebytes);
        }
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }
}