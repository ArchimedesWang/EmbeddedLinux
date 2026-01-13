#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *fp;
    fp = fopen("./haha.txt", "r");
    if(fp == NULL) {
        perror("Open");
    } else {
        perror("Open");
    }

    fclose(fp);

    return 0;
}