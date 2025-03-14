//programs using the I/O system calls of Linux operating system (open, read, write)
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
    int fd=open("file.txt", O_CREAT | O_RDWR,"S_IRWXU");
    if(fd<0){
        printf("ERROR");
        exit(1);
    }
    char wbuf[128]="hello how are u?";
    write(fd,wbuf,strlen(wbuf));
    printf("content written\n");
    lseek(fd,0,SEEK_SET);
    char rbuf[128];
    read(fd,rbuf,100);
    printf("content read\n");
    printf("%s\n",rbuf);
    close(fd);
}