#include<stdio.h>
void main()
{
    int n,size,initial,move,rq[20],Totalheadmovement=0;
    printf("Enter ther number of requests:");
    scanf("%d",&n);
    printf("Enter the Requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }

    printf("Enter the initial head position:");
    scanf("%d",&initial);
    printf("Enter the total disk size:");
    scanf("%d",&size);
    printf("Enter the direction to move first from the initial head position(high=1,low=0):");
    scanf("%d",&move);

    for(int p=1;p<n;p++) //Bubble sort
    {                    
        for(int c=0;c<n-p;c++)
        {
             if(rq[c]>rq[c+1]){
                int temp=rq[c];
                rq[c]=rq[c+1];
                rq[c+1]=temp;
             }
        }
    }

    int index;
    for(int i=0;i<n;i++)
    {
        if(initial<rq[i]){
            index=i;
            break;
        }
    }

    if(move==1)//towards high
    {
        if(index!=0)
        {
            Totalheadmovement=(size-1)-initial;
            Totalheadmovement=Totalheadmovement+((size-1)-0);
            Totalheadmovement=Totalheadmovement+(rq[index-1]-0);
        }
        else{
            Totalheadmovement=rq[n-1]-initial;
        }
    }
    
    if(move==0){//towards low
         if(index!=n-1)
         {
            Totalheadmovement=(initial-0);
            Totalheadmovement=Totalheadmovement+((size-1)-0);
            Totalheadmovement=Totalheadmovement+((size-1)-rq[index]);
         }
         else{
            Totalheadmovement=initial-rq[0];
         }
    }
    printf("Total head movement is:%d",Totalheadmovement);
}