#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define LEN 1024

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("请输入两串字符\n");
        return -1;
    }

    int fd1 = open("1.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if(fd1 == -1) {
        perror("Open");
        return -1;
    }

    int len1 = strlen(argv[1]);
    if(write(fd1, argv[1], len1) != len1) {
        perror("Write");
        close(fd1);
        return -1;
    }

    int fd2 = dup(fd1);
    if(fd2 == -1) {
        perror("Open");
        return -1;
    }

    int len2 = strlen(argv[2]);
    if(write(fd2, argv[2], len2) != len2) {
        perror("Write");
        close(fd1);
        close(fd2);
        return -1;
    }   

    if(lseek(fd1, 0, SEEK_SET) == -1) {
        perror("Lseek");
        close(fd1);
        close(fd2);
        return -1;
    }

    int len = len1 + len2;

    char *buffer = malloc(len+1);
    if(read(fd1, buffer, (size_t)len) != len) {
        perror("Read");
        free(buffer);
        close(fd1);
        close(fd2);
        return -1;
    }
    buffer[len] = '\0';

    printf("Read text: %s\n", buffer);

    free(buffer);
    close(fd1);
    close(fd2);

    return 0;
}