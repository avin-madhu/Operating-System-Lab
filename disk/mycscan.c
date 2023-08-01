#include <stdio.h>
int main()
{
    int RQ[100],diff[100],n,size,initial,p=0,a[100],total=0;
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

    RQ[n]=initial;
    RQ[n+1]=0;
    RQ[n+2]=size-1;
    n=n+3;
     
     // sorting the request array 
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
    
   for(int i=0;i<n;i++)
  {
    if(RQ[i]==initial)
    {
      index=i;
      break;
    }
  }

  if(initial<(size-1-initial))
  {
    for(int i=index;i>=0;i--,p++)
    {
      a[p]=RQ[i];
    }
    for(int i=n-1;i>index;i--,p++)
    {
        a[p]=RQ[i];
    }
  }
  else
  {
    for(int i=index;i<n;i++,p++)
    {
        a[p]=RQ[i];
    }
    for(int i=0;i<index;i++,p++)
    {
        a[p]=RQ[i];
    }
  }
  printf("TRAVERSED ORDER : ");
  for(int i=0;i<p;i++)
  {
    printf("%d => ",a[i]);
  }

  for(int j=0;j<p-1;j++)
  {
    int diff=0;
    if(a[j]>a[j+1])
    {
      diff=a[j]-a[j+1];
    }
    else
    {
      diff=a[j+1]-a[j];
    }
    total=total+diff;
  }

  printf("\nTotal head movements: %d",total);

}