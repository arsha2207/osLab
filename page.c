#include<stdio.h>

int f,rn,req[100],fr[10],hit,fault,found;
int j,k ,i;

void display(int i)
{
    printf("%d: ", i);
    for(i=0;i<f;i++)
    {
        if (fr[i]==-1)
            printf("__  ");
        else
            printf("%d  ",fr[i]);
    }
    printf("\n");
}

void fcfs()
{
    int index=0;
    hit=fault=0;
    for(i=0;i<f;i++) {
        fr[i]=-1;
    }

    for(i=0;i<rn;i++)
    {
        found=0;
        for(j=0;j<f;j++){ // check for page fault
            if(fr[j]==req[i])
            {
                found=1;
                hit++;
                break;
            }
        }

        if(!found) // page fault
        {
            fr[index]=req[i];
            index=((index+1)%f);
            fault++;
        }
        display(req[i]);
    }

    printf("\npage fault=%d\nHITs=%d\n",fault,hit);
}

void lru()
{
    int recent[f];
    hit=fault=0;
    for(i=0;i<f;i++) {
        fr[i]=-1;
        recent[i]=-1;
    }

    for(i=0;i<rn;i++)
    {
        found=0;
        for(j=0;j<f;j++){ // check for page fault
            if(fr[j]==req[i])
            {
                found=1;
                hit++;
                recent[j]=i;
                break;
            }
        }

        if(!found) // page fault
        {
            int min=0;
            for(j=1;j<f;j++){
                if(recent[j]<recent[min])
                    min=j;
            }
            fr[min]=req[i];
            recent[min]=i;
            fault++;
        }
        display(req[i]);
    }

    printf("\npage fault=%d\nHITs=%d\n",fault,hit);
}

void lfu()
{
    int freq[10]={0};
    int order[f];
    hit=fault=0;
    for(i=0;i<f;i++) {
        fr[i]=-1;
        order[i]=-1;
    }

    for(i=0;i<rn;i++)
    {
        found=0;
        freq[req[i]]++;

        for(j=0;j<f;j++){ // check for page fault
            if(fr[j]==req[i])
            {
                found=1;
                hit++;
                break;
            }
        }
        if(!found) // page fault
        {
            fault++;
            for(j=0;j<f;j++){ // check for empty space
                if(fr[j]==-1)
                {
                    fr[j]=req[i];
                    order[j]=i;
                    display(req[i]);
                    break;
                }
            }
            if(j!=f)// empty space found
                continue;

            // find least frequency page
            int min=0;
            for(j=1;j<f;j++){
                if(freq[fr[j]]<freq[fr[min]])
                    min=j;
                else if((freq[fr[j]]==freq[fr[min]])&&(order[j]<order[min]))
                    min=j;
            }
            fr[min]=req[i]; // replace page
            order[min]=i;
        }
        display(req[i]);
    }

    printf("\npage fault=%d\nHITs=%d\n",fault,hit);
}

void main() {

    printf("\nEnter no. of frames : ");
    scanf("%d",&f);
    printf("length of reference string : ");
    scanf("%d",&rn);

    printf("Enter sequence :\n");
    for(i=0;i<rn;i++) {
        scanf("%d",&req[i]);
    }

    printf("\nFCFS\n\n");
    fcfs();
    printf("\nLRU\n\n");
    lru();
    printf("\nLFU\n\n");
    lfu();
}