#include <stdio.h>
int main()
{
    int n,bt[10],p[10],pro[10],wt[10],tat[10];
    float awt=0,atat=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        pro[i]= i+1;
    }

    printf("Enter the burst and priority of each process: \n");

    for(int i=0; i<n; i++)
    {
      printf("P%d: ",i+1);
      scanf("%d %d",&bt[i],&p[i]);
    }

    // sorting according to the priority
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(p[j]>p[j+1])
            {
                int temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;

                temp = pro[j+1];
                pro[j+1] = pro[j];
                pro[j] = temp;

                temp = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = temp;
            }
        }
    }
   
    wt[0] = 0;

    printf("Pr\tBT\tPrio\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
       wt[i] =0;
       tat[i] = 0;
       for(int j=0;j<i;j++)
       {
          wt[i] += bt[j];
       }

       tat[i] = wt[i] + bt[i] ;
       awt += wt[i];
       atat += tat[i];

       printf("%d\t%d\t%d\t%d\t%d\n",pro[i],bt[i],p[i],wt[i],tat[i]);
    }

    printf("\nAverage waiting time: %f\n",awt/n);
    printf("Average turnaround time: %f",atat/n);
}