/** C program to demonstrate the use of fork() system call */

#include <stdio.h>
#include <unistd.h>

int main()
{
    int n;
     
    printf("Enter the Limit: ");
    scanf("%d",&n);
    int check = fork();

    if(check>0) // parent process
    {
        printf("Even numbers upto %d: ",n);
        for(int i = 0;i<n;i++)
        {
            if(i%2==0)
            {
                printf("%d ",i);
            }
        }
    }
    if(check==0)  // child process
    {
        
        printf("\nOdd numbers upto %d: ",n);
        for(int i=0;i<n;i++)
        {
            if(i%2!=0)
            {
                printf("%d ",i);
            }
        }
    }

    return 0;
}
