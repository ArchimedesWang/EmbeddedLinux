#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // int fd;
    // if((fd = open("test", O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1) {
    //     perror("Open");
    //     return -1;
    // } 

    // sleep(10);
    if(unlink("test.txt") < 0) perror("Unlink");

    return 0;
}