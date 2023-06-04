#include<stdio.h>

void CalculatewaitingTime(int Process[],int n,int burstTime[],int waitingTime[],int arrivalTime[])
{
    int serviceTime[n];
    serviceTime[0]=0;
    waitingTime[0]=0;

    for (int i = 1; i < n; i++)
    {
        serviceTime[i]=serviceTime[i-1]+burstTime[i-1];
        waitingTime[i]=serviceTime[i]-arrivalTime[i];
        
        if (waitingTime[i]<0)
        {
            waitingTime[i]=0;
        }   
    }
}

void CalculateTurnAroundTime(int Process[],int n,int burstTime[],int waitingTime[],int turnAroundTime[])
{
    for(int i=0;i<n;i++)
        turnAroundTime[i]=burstTime[i]+waitingTime[i];
}


void findAvgTime(int Process[],int n,int burstTime[],int arrivalTime[])
{
    int waitingTime[n],turnAroundTime[n];

    CalculatewaitingTime(Process,n,burstTime,waitingTime,arrivalTime);
    CalculateTurnAroundTime(Process,n,burstTime,waitingTime,turnAroundTime);

    printf("\n-----------------------------------------------------------------------------------------");
    printf("\nProcess  Burst Time    Arrival Time   Waiting Time  Turn-Around Time  Completion Time");
    printf("\n-----------------------------------------------------------------------------------------");
    int total_waitingTime=0,total_turnAroundTime=0;


    for (int i = 0; i < n; i++)
    {
        total_waitingTime=total_waitingTime+waitingTime[i];
        total_turnAroundTime=total_turnAroundTime+turnAroundTime[i];
        int compl_time=turnAroundTime[i]+arrivalTime[i];

        printf("\n%6d  %8d  %13d  %14d  %15d %15d",i,burstTime[i],arrivalTime[i],waitingTime[i],turnAroundTime[i],compl_time);
    }

    printf("\n-----------------------------------------------------------------------------------------");
    printf("\n");
    printf("\nAverage Waiting Time = %0.3f",(float)total_waitingTime/(float)n);
    printf("\nAverage Turn Around Time = %0.3f",(float)total_turnAroundTime/(float)n);
    printf("\n\n");
}

void main()
{
    int Process[20],n,burstTime[20],arrivalTime[20],i;

    printf("Enter the number of Processes:");
    scanf("%d",&n);

    printf("\nEnter the burst Times of each Process: ");
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ",i+1);
        scanf("%d",&burstTime[i]);
    }

    printf("\nEnter the Arrival time of each Process:");
    printf("\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ",i+1);
        scanf("%d",&arrivalTime[i]);
    }

    findAvgTime(Process,n,burstTime,arrivalTime);
}