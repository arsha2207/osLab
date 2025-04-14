//program using stat() system call
#include<stdio.h>
#include<sys/stat.h>

int main()
{
    struct stat file;
    stat("head",&file);
    printf("file size is %ld\n",file.st_size);
    printf("user id is %d\n",file.st_uid);
    printf("mode is %d\n",file.st_mode);
    return 0;
    
}