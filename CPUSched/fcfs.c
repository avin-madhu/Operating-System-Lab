#include <stdio.h>
#define max 10
int main()
{
   
   int bt[max],at[max],wt[max],tat[max],twt=0,ttat=0,temp[max],n;
   printf("Enter the number of processes: ");
   scanf("%d",&n);
   printf("Enter the burst time of each: ");
   for(int i=0;i<n;i++)
   {
      printf("\nprocess - %d: ",i+1);
      scanf("%d",&bt[i]);
   }
   printf("Enter the arrival time of each: ");
   for(int i=0;i<n;i++)
   {
      printf("\nprocess - %d: ",i+1);
      scanf("%d",&at[i]);
   }

   printf("PR\tBT\tAT\tWT\tTAT\n");
    temp[0] =0;
   for(int i=0;i<n;i++)
   {
       wt[i]=0;
       tat[i]=0;
       temp[i+1] = temp[i] + bt[i];
       wt[i] = temp[i] - at[i];
       tat[i] = wt[i] + bt[i];
       twt = twt + wt[i];
       ttat = ttat + tat[i];

       printf("P%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],at[i],wt[i],tat[i]);
   }
   float awt = twt/n;
   float atat = ttat/n;

   printf("\nAverage waiting Time: %f",awt);
   printf("\nAverage turn Around time: %f",atat);

}