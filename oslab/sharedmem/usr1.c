//USR1

#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

struct shared{
        char msg[128];
        int datastat;
        int usr1,usr2;
};

void main()
{
        struct shared *shmptr;
        key_t key=ftok("sharemem",23);
        int shmid=shmget(key,sizeof(struct shared),IPC_CREAT|0600);
        shmptr=(struct shared*)shmat(shmid,NULL,0);

        shmptr->usr1=getpid();
        shmptr->datastat=1;
        shmptr->usr2=0;

        while(shmptr->usr2==0);

        while(1){
                while(shmptr->datastat==1);
                printf("message frm usr:%s\n", shmptr->msg);
                printf("ur reply:");
                fgets(shmptr->msg,128,stdin);
                shmptr->datastat=1;
        }
        shmdt((void *)shmptr);
        shmctl(shmid,IPC_RMID,NULL);
}

