#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("usage: cat filename\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 1; i < argc; i++){
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            printf("error: cannot open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        off_t size = (fd,0,SEEK_END);   //* sets the file pointer to the end of the file and size to file_size
        if(size == -1){
            printf("error: failed to seek");
            exit(EXIT_FAILURE);
        }
        int nbytes;
        char buffer[BUFFER_SIZE];
        while(size % BUFFER_SIZE == 0){
            size = lseek(fd, size - BUFFER_SIZE, SEEK_CUR);
            nbytes = read(fd, buffer, BUFFER_SIZE);
            write(STDOUT_FILENO, buffer, nbytes);
            nbytes = read(fd, buffer, BUFFER_SIZE);
            }
        
        }

        close(fd);
    }
    exit(EXIT_SUCCESS);
}