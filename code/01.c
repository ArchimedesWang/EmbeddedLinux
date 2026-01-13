#include <stdio.h>
#include <unistd.h>

int main() {
    for(int i=0; i<500; i++)
        printf("%d", i);
    while(1) {
        sleep(1);
    } 
    return 0;
}