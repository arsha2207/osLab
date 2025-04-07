#include<stdio.h>

int mem[20],frag[20],alloc[20],m,r;

int req[20],i,j,arr[20]; 

void op()
{
    printf("\tblock\talloc\tfragment\n");
    int extfrag=0;
    for(int j=0;j<m;j++)
    {
        printf("\t%d\t%d\t%d\n",mem[j],alloc[j],frag[j]);
        if(alloc[j]==0)
        {
            extfrag+=mem[j];
        }
    }
    printf("total external fragmentation:%d\n",extfrag);
    
}

void ff()
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<m;j++)
        {
            if((alloc[j]==0) && (mem[j]>=req[i]))
            {
                alloc[j]=req[i];
                frag[j]=mem[j]-alloc[j];
                break;
            }
        }
    }
    op();
}

void bf()
{
    for(int i=0;i<m;i++)
    {
        frag[i]=alloc[i]=0;
    }
    int temp;
    for(i=1;i<m;i++)
    {
        for(j=0;j<m-i;j++)
        {
            if(mem[j]>mem[j+1])
            {
                temp=mem[j];
                mem[j]=mem[j+1];
                mem[j+1]=temp;
            }
        }
    }
    ff();
}

void wf()
{
    for(int i=0;i<m;i++)
    {
        frag[i]=alloc[i]=0;
    }
    for(i=0;i<r;i++)
    {
        for(j=m-1;j>=0;j--)
        {
            if((alloc[j]==0) && (mem[j]>=req[i]))
            {
                alloc[j]=req[i];
                frag[j]=mem[j]-alloc[j];
                break;
            }
        }
    }
    op();
}

void main()
{
    printf("no. of memory blocks:");
    scanf("%d",&m);
    printf("no. of requests:");
    scanf("%d",&r);
    
    printf("Memory blocks:");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&mem[i]);
        frag[i]=alloc[i]=0;
    }
    printf("Request:");
    for(int i=0;i<r;i++)
    {
        scanf("%d",&req[i]);
    }
    
    printf("\nFirst Fit\n");
    ff();
    printf("\nBest Fit\n");
    bf();
    printf("\nWorst Fit\n");
    wf();
    
}