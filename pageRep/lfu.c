#include<stdio.h>
void main()
{
    int f,p,pages[50],frame[10],hit=0,count[50],time[50];
    int i,j,flag,least,mintime,temp;
    printf("Enter the number of frames");
    scanf("%d",&f);
    printf("Enter the number of pages");
    scanf("%d",&p);
    for(i=0;i<f;i++){
        frame[i]=-1;
    }
    for(i=0;i<50;i++)
    {
        count[i]=0;
    }
    printf("Enter the reference page string");
    for(i=0;i<p;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("\n");
    for(i=0;i<p;i++)
    {
        count[pages[i]]++;
        time[pages[i]]=i;
        flag=1;
        least=frame[0];
        for(j=0;j<f;j++)
        {
            if(frame[j]==-1||frame[j]==pages[i])
            {
                  if(frame[j]!=-1)
                  {
                    hit++;
                  }
               flag=0;
               frame[j]=pages[i];
               break;
            }
            if(count[frame[j]]<count[least])
            {
                least=frame[j];
            }
        }
        if(flag)
        {
            mintime=50;
            for(j=0;j<f;j++)
            {
                 if(count[frame[j]]==count[least]&&time[frame[j]]<mintime)
                 {
                    temp=j;
                    mintime=time[frame[j]];
                 }
            }
            count[frame[temp]]--;
            frame[temp]=pages[i];
        }
        for(j=0;j<f;j++)
        {
            printf("%d",&frame[j]);
        }
        printf("\n");
        printf(" Total page hit=%d",hit);
        printf("Total Page fault=%d",p-hit);
    }

}