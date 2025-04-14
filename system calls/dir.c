// system calls used are opendir(), closedir(), readdir()

#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
void main()
{
    DIR *d;
    struct dirent *dir;
    char buff[256];
    printf("enter dir name:");
    scanf("%s",buff);
    if((d=opendir(buff))==NULL)
    {
        printf("ERROR\n");
        exit(1);
    }
    while(dir=readdir(d))
    {
        printf("%s\n",dir->d_name);
    }
    closedir(d);
}
