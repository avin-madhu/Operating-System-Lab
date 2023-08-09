#include <stdio.h>
int fragments[10];
void firstFit(int blockSize[],int m,int processSize[],int n)
{
   int allocated[10];

   for(int i = 0; i <n;i++)
   {
      allocated[i] = -1;
   }

   for(int i=0;i<n;i++)
   {
      for(int j = 0; j <m; j++)
      {
         if(blockSize[j] >= processSize[i])
         {
            allocated[i] = j;
            blockSize[j] -= processSize[i];
            fragments[j] = blockSize[j];
            break;
         }
      }
   }

   printf("\nProcess\t\tdataSize\t\tallocated\n");
   for(int i = 0; i <n;i++)
   {
      printf("%d\t\t%d\t\t\t",i+1,processSize[i]);
      if(allocated[i]==-1)
      {
         printf("Not allocated\n");
      }
      else{
          printf("%d\n",allocated[i]+1);
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
      fragments[i]=blockSize[i];
    }
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the Process size of each: ");
    for(int i=0; i<n; i++)
    {
      scanf("%d",&ProcessSize[i]);
    }
    firstFit(blockSize,m,ProcessSize,n);

}