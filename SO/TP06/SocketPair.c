#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024
int main(int argc, char* argv []) {
    char buf[BUF_SIZE];
    int sockets[2], retv;
    retv = socketpair(AF_UNIX, SOCK_STREAM, 0, sockets);
    if (retv == -1) { perror("socketpair"); exit(EXIT_FAILURE); }
    retv = fork();
    if (retv == -1) { perror("fork"); exit(EXIT_FAILURE); }
    if (retv > 0) { /* parent */
        if (argc <= 1) { perror("No File Argument was given"); exit(EXIT_FAILURE); }
        close(sockets[1]); // close out the socket side associated to the child process
        char fileName[BUF_SIZE];
        strcpy(fileName, argv[1]);
        write(sockets[0], fileName, sizeof(fileName));
        int n;
        while (n = read(sockets[0], buf, BUF_SIZE)){
            write(STDOUT_FILENO, buf,n);
        }
        close(sockets[0]);
        retv = wait(NULL);
        if (retv == -1) { perror("wait"); exit(EXIT_FAILURE); }
    }
    else { /* child */
        char string2 [] = "...one receives far more than he seeks.";
        close(sockets[0]); // close out the socket side associated to the parent process
        char text[BUF_SIZE];
        int nbytes;
        read(sockets[1], buf, sizeof(buf));
        int file = open(buf, O_RDONLY);
        if (file < 0) { perror("Invalid File Path"); exit(EXIT_FAILURE); }
        while (nbytes = read(file, text, BUF_SIZE)) {
           for(int i = 0; i <= nbytes; i++){
                if(text[i] >= 'a' && text[i] <= 'z') text[i] += 'A' - 'a'; 
            }
            write(sockets[1], text, nbytes);
        }
        close(sockets[1]);
        exit(EXIT_SUCCESS);
    }
}