#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char* argv []) {
    FILE* history_file = fopen("history.txt", "a");
    if (history_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    for (;;) {
        /* give prompt, read command and null terminate it */
        fprintf(stdout, "$ ");
        char buf[1024];
        char* command = fgets(buf, sizeof(buf), stdin);
        if (command == NULL)
            break;
        command[strlen(buf) - 1] = '\0';

        // write command to history file
        fprintf(history_file, "%s\n", command);
        fflush(history_file);

        /* split command into arguments */
        char* args[100];
        int i = 0;
        char* token;
        char* rest = command;
        while((token = strsep(&rest, " ")) != NULL) {
            if (strlen(token) > 0)
                args[i++] = token;
        }
        args[i] = NULL;

        /* check for exit */
        if (strcmp(args[0], "exit") == 0)
            break;
        if (strcmp(args[0], "myhistory") == 0) {
            args[0] = "tail"; //command to run
            args[3] = args[1]; //number of lines
            args[2] = "-n"; //argument for number of lines
            args[1] = "history.txt"; //file to read
        }

        /* call fork and check return value */
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) {
            /* child */
            int retv = execvp(args[0], args);
            if (retv == -1) {
                perror("execlp");
                exit(EXIT_FAILURE);
            }
        }
        /* shell waits for command to finish before giving prompt again */
        int retv = waitpid(pid, NULL, 0);
        if (retv == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
    // close history file
    fclose(history_file);
    exit(EXIT_SUCCESS);
}

