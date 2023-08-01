#include <stdio.h>
int main()
{
    int n,rs[30],f,m[10],count[10],flag[30],next=0,min=0,pf=0;
    printf("Enter the length refrence string: ");
    scanf("%d",&n);
    printf("Enter the reference string: ");
    for(int i=0; i<n; i++)
    {
      scanf("%d",&rs[i]);
      flag[i]=0;
    }
    printf("Enter the number of frames: ");
    scanf("%d",&f);
    for(int i=0; i<f; i++) //initialising the frame
    {
        count[i]=0;
        m[i] = -1;
    }
    printf("The page replacement process is: \n\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<f; j++) // checking for hit
        {
            if(m[j]==rs[i])
            {
                flag[i]=1;
                count[j]=next;
                next++;
                
            }
        }

        if(flag[i]==0) // page fault condition
        {
            if(i<f)
            {
                m[i] = rs[i];
                count[i]=next;
                next++;
            }
            else
            {
               min=0;
               for(int j=1; j<f; j++)
               {
                  if(count[min]>count[j])
                  {
                    min=j;
                  }
               }
               m[min]=rs[i];
               count[min]=next;
               next++;
            }
            pf++;
        }
        for(int j=0; j<f; j++)
        {
            printf("%d\t",m[j]);
        }
        if(flag[i]==0)
        {
            printf("\t M");
            printf("\n");
        }
    }
    printf("\n\nThe number of page Faults = %d",pf);

}