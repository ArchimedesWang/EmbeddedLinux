#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buff[] = "ABCDEFGHIJ";
    int fp1 = open("haha.txt", O_RDWR);
    if (fp1 == -1)
    {
        perror("Open");
    }
    int fp2 = creat("xixi.txt", 0777);
    if (fp2 == -1)
    {
        close(fp1);
        perror("Creat");
    }

    // 比较普通文件和空洞文件
    for (int i = 0; i < 1000; i++)
    {
        if (write(fp1, buff, 10) == -1)
        {
            perror("Fp1 Write");
            close(fp1);
            close(fp2);
        }
    }

    if (lseek(fp2, 9990, SEEK_SET) == -1)
    {
        perror("Fp2 Lseek");
        close(fp1);
        close(fp2);
    }
    if (write(fp2, buff, 10) == -1)
    {
        perror("Fp1 Write");
        close(fp1);
        close(fp2);
    }

    close(fp1);
    close(fp2);
    return 0;
}