#include <stdio.h>


void BestFit(int blockSize[],int m,int processSize[],int n)
{
    int allocation[n];

    for(int i=0;i<n;i++)// indicate initially no process is allocated
    {
      allocation[i] = -1;
    }


    for(int i=0;i<n;i++)
    {
       int bestIndex = -1;
       for(int j=0;j<m;j++)
       {
          if(blockSize[j]>=processSize[i])
          {
             if(bestIndex==-1)
             {
               bestIndex = j;
             }
             else if(blockSize[bestIndex]>blockSize[j])
             {
                 bestIndex = j;
             }
          }
       }

       if(bestIndex !=-1)// was able to find a block
       {
          allocation[i] = bestIndex;
          blockSize[bestIndex] -= processSize[i];
       }
    }

    printf("\nProcess\t\tdataSize\t\tallocated\t\tFragments\n");
   for(int i = 0; i <n;i++)
   {
      printf("%d\t\t%d\t\t\t",i+1,processSize[i]);
      if(allocation[i]==-1)
      {
         printf("Not allocated\n");
      }
      else
      {
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
    BestFit(blockSize,m,ProcessSize,n);

}