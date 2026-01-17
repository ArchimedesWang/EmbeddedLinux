#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h> // ENOENT
#include <time.h>
#include <string.h>

#define LEN 1024

int main(int argc, char* argv[])
{
    /* 日志目录初始化
    /*  1. 目录初始化
    /*      1) 目录是否存在
    /*          2) 存在检查权限
    /*          3）不存在创建
    /* 2. 日志文件初始化
    /*      1) 日志文件是否存在
    /*          2) 存在追加
    /*          3）不存在创建
    */
    struct stat dirstat;
    if (stat("./log", &dirstat) == -1) {
        if (errno == ENOENT) {
            perror("Dir");
        }
        if(mkdir("./log", 0755) == -1){
            perror("MakeDir");
            return -1;
        } 
        printf("Cteate Log Dir successful!\n");  
    } else if (S_ISDIR(dirstat.st_mode)) {
        // 检查权限
        if ((dirstat.st_mode & S_IWUSR) && (dirstat.st_mode & S_IXUSR)) ;
        else chmod("./log", 0755);
    } else {
        perror("Not Dir");
        return -1;
    }                

    // 2. 日志初始化
    int fd;
    if ((fd = open("./log/log.txt", 
                    O_RDWR | O_CREAT | O_APPEND, 
                    0755)) == -1) {
        perror("Open");
        return -1;
    } 

    // 3. 日志写入
    char buffer[LEN] = {'\0'};
    time_t nowtime;
    struct tm tm;

    if (time(&nowtime) == (time_t)-1) {
        perror("Time");
        return -1;
    }

    if (localtime_r(&nowtime, &tm) == NULL) {
        perror("Localtime_r");
        return -1;
    }

    size_t len = strftime(buffer, sizeof(buffer),
                        "%Y-%m-%d %H:%M:%S\n",
                        &tm);
    if (len == 0) {
        perror("Strftime");
        return -1;
    }

    buffer[len-1] = ' ';

    pid_t pidid = getpid();
    snprintf((buffer+len) , sizeof(buffer), "Pid is %d\n", pidid);

    ssize_t n = write(fd, buffer, strlen(buffer));
    if (n != strlen(buffer)) {
        perror("write");
        return -1;
    }

    // 3. 日志轮转
    float filesize = dirstat.st_size;

    if(filesize >= 4 * 1024) {
        close(fd);
        if(rename("./log/log.txt", "./log/log1.txt") == -1) {
            perror("link");
            return -1;
        }
        if((fd = open("./log/log.txt", O_RDWR | O_CREAT | O_TRUNC, 0664)) == -1) {
            perror("Open new");
            return -1;
        }
    }

    return 0;
}