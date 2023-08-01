#include <stdio.h>
int main()
{
    int n,remain, at[10],bt[10],q,time;
    int rt[10],flag=0,sumWait=0,sumturnAroundTime=0;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    remain=n;
    printf("Enter the Burst time and arrival time for each process: \n\n");
    for(int i=0;i<n;i++)
    {
        printf("p%d: ",i+1);
        scanf("%d %d", &at[i],&bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the Quantum Time: ");
    scanf("%d",&q);
    for(int i=0,time=0;remain!=0;)
    {
         if(rt[i]<=q && rt[i]>0)
         {
            time+=rt[i];
            rt[i]=0;
            flag=1;
         }
         else if(rt[i]>0)
         {
            rt[i]-=q;
            time+=q;
         }
         if(rt[i]==0&&flag==1)
         {
            remain--;
            sumWait+=time-at[i]-bt[i];
            sumturnAroundTime+=time-at[i];
            flag=0;
         }
         if(i==n-1)
         {
            i=0;
         }
         else if(at[i+1]<=time)
         {
            i++;
         }
         else
         {
            i=0;
         }
    }
    printf("\nAverage Waiting Time: %f\n",(sumWait*1.0)/n);
    printf("\nAverage turn Around time: %f",(sumturnAroundTime*1.0)/n);

}