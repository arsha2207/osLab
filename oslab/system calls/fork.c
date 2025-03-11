#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid = fork();
    int var=10;
    if(pid<0)
    {
        printf("Error in fork\n");
        exit(1);
    }
    else if(pid==0)
    {
        printf("I am the child\n");
        var=var+1;
        printf("%d\n",var);
        printf("the pid is %d\n",getpid());
    }
    else
    {
        printf("I am the parent\n");
        var=var+2;
        printf("%d\n",var);
        printf("the pid is %d\n",getpid());
    }
}