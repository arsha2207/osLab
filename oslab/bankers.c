#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int p,r,available[10],max[10][10],need[10][10],alloc[10][10],i,j,seq[10];

void reqalg()
{
    int req[r],a;
    printf("enter req id");
    scanf("%d",&a);
    printf("enter req seq");
    for(j=0;j<r;j++)
    {
        scanf("%d",&req[j]);
    }
    for(j=0;j<r;j++)
    {
        if(req[j]>need[a][j])
            break;
    }
    if(j!=r)
    {
        printf("req>need");
        exit(0);
    }
    for(j=0;j<r;j++)
    {
        if(req[j]>available[j])
            break;
    }
    if(j!=r)
    {
        printf("req>available");
        exit(0);
    }
    for(j=0;j<r;j++)
    {
        available[j]-=req[j];
        need[a][j]-=req[j];
        alloc[a][j]+=req[j];
    }
}

bool safealgo()
{
    int count=0;
    int finish[10]={0};
    while(count<p)
    {
        int found=0;
        for(i=0;i<p;i++)
        {
            if(!finish[i])
            {
                for(j=0;j<r;j++)
                {
                    if(need[i][j]>available[j])
                            break;
                }
                if(j==r)
                {
                    for(j=0;j<r;j++)
                    {
                        available[j]+=alloc[i][j];
                    }
                    finish[i]=1;
                    found=1;
                    seq[count++]=i;
                }
            }
        }
        if(!found)
            return false;
    }
    return true;
}

void main()
{
    printf("enter proces no.");
    scanf("%d",&p);
    printf("enter res no.");
    scanf("%d",&r);
    printf("available res");
    for(j=0;j<r;j++)
    {
        scanf("%d",&available[j]);
    }
    printf("max");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("alloc");
    for(i=0;i<p;i++)
    {
        for(j=0;j<r;j++)
        {
            scanf("%d",&alloc[i][j]);
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    int c;
    printf("enter 0 if any request:");
    scanf("%d",&c);
    if (!c)
    {
        reqalg();
    }
    bool f=safealgo();
    if(f)
    {
        printf("safe\n");
        for(i=0;i<p;i++)
        {
            printf("%d  ",seq[i]);
        }
    }
    else
        printf("not safe\n");
}