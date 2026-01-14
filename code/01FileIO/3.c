#include <stdio.h>
#include <fcntl.h>

void set_fl(int fd, int flags) {
    int val;
    if((val = fcntl(fd, F_GETFL)) == -1) {
        perror("F_GETFL");
        close(fd);
        return ;
    }

    val |= flags;

     if((val = fcntl(fd, F_SETFL, val)) == -1) {
        perror("F_SETFL");
        close(fd);
        return ;
    }   
}

int main(int argc, char *argv[]) {


    return -1;
}