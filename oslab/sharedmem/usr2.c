
//USR2


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

        shmptr->usr2=getpid();

        while(1){
                printf("msg:");
                fgets(shmptr->msg,128,stdin);
                shmptr->datastat=2;
                while(shmptr->datastat!=1);
                printf("message frm usr:%s\n", shmptr->msg);
        }
        shmdt((void *)shmptr);
        shmctl(shmid,IPC_RMID,NULL);
}



