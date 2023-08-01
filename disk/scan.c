#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,RQ[20],initial,size,move,totalHeadMovement=0;
    printf("Enter the number of requests: \n");
    scanf("%d", &n);
    printf("Enter the Request sequence: ");
    for(int i = 0; i < n; i++)
    {
      scanf("%d", &RQ[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &initial);
    printf("Enter the total disk size: ");
    scanf("%d", &size);
    printf("Enter the direction to move (high=1, low=0): ");
    scanf("%d", &move);

    // request array sort

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp = RQ[j]; 
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }
    int index;
    for(int i = 0; i < n; i++)// get the next largest from the head
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
    int i;
    if(move==1) // towards high value
    {
       for( i = index; i < n ; i++)
       {
         totalHeadMovement += abs(RQ[i] - initial);
         initial = RQ[i];
       }
    
       totalHeadMovement += abs(size - RQ[i-1] - 1);
       initial = size-1;
       
       for(i=index; i>=0; i--)
       {
        totalHeadMovement += abs(RQ[i] - initial);
        initial = RQ[i];
        }
    }
    else // towards the low value
    {
       for( i = index-1; i>=0 ; i--)
       {
          totalHeadMovement+= abs(RQ[i] - initial);
          initial = RQ[i];
       }
       totalHeadMovement += abs(RQ[i+1]-0);
       initial = 0;
       for(i=index;i<n;i++)
       {
         totalHeadMovement += abs(RQ[i] - initial);
         initial = RQ[i];
       }
    }

    printf("Total head movement is : %d", totalHeadMovement);
    return 0;
}
