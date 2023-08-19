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
    for(int i=1;i<n;i++) //Bubble sort
    {
        for(int j=0;j<n-i;j++)
        {
             if(rq[j]>rq[j+1]){
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
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
            Totalheadmovement=Totalheadmovement+((size-1)-rq[0]);
        }
        else{
            Totalheadmovement=rq[n-1]-initial;
        }
    }
    if(move==0){//towards low
         if(index!=n-1)
         {
             Totalheadmovement=(initial-0);
             Totalheadmovement=Totalheadmovement+(rq[n-1]-0);
         }
         else{
            Totalheadmovement=initial-rq[0];
         }
    }
    printf("Total head movementis:%d",Totalheadmovement);
}