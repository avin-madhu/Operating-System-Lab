#include <stdio.h>

void worstFit(int blockSize[],int m,int processSize[],int n)
{
   int allocation[n];

   for(int i=0;i<n;i++)
   {
    allocation[i] = -1;
   }

   for(int i=0;i<n;i++)
   {
      int worstIndex=-1;
      for(int j=0;j<m;j++)
      {
         if(blockSize[j]>=processSize[i])
         {
            if(worstIndex==-1)
            {
                worstIndex=j;
            }
            else if(blockSize[worstIndex]<blockSize[j])
            {
                worstIndex=j;
            }
         }
      }
      if(worstIndex!=-1)
      {
        allocation[i]=worstIndex;
        blockSize[worstIndex] -= processSize[i];
      }
   }

   printf("\nProcess\t\tdataSize\t\tallocated\t\tfragments\n");
   for(int i = 0; i <n;i++)
   {
      printf("%d\t\t%d\t\t\t",i+1,processSize[i]);
      if(allocation[i]==-1)
      {
         printf("Not allocated\n");
      }
      else{
          printf("%d\t\t\t%d\n",allocation[i]+1,blockSize[i]);
      }
   }

}


int main()
{
    int m,n,blockSize[10],ProcessSize[10];
    printf("Enter the number of Blocks: ");
    scanf("%d",&m);
    printf("Enter the Block sizes of each: ");
    for(int i=0; i<m; i++)
    {
      scanf("%d",&blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the Process size of each: ");
    for(int i=0; i<n; i++)
    {
      scanf("%d",&ProcessSize[i]);
    }
    worstFit(blockSize,m,ProcessSize,n);

}