/**A program to create two process, one process (parent process) must add number upto a limit 
 * n at the same time child process must add even numbers also print the process id s.
*/

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int main()
{
    int arr[100],n;
    int sumEven=0,sumOdd=0;
    printf("Enter the limit: ");
    scanf("%d ",&n);
    int check = fork();
    int id;
    if(check==0)//child process
    {
         id = getppid();
        for(int i =0;i<n;i++)
        {
            if(i%2==0)
            {
                sumEven+=i;
            }
        }
    }
    printf("The sum of Even numbers: %d\n",sumEven);
    printf("The child id: %d\n\n",id);

    if(check!=0)// parent process
    {
        int id = getpid();
        for(int i =0;i<n;i++)
        {
            if(i%2!=0)
            {
                sumOdd+=i;
            }
        }
    }
    printf("The sum of Odd numbers: %d\n",sumOdd);
    printf("The child id: %d\n\n",id);

    return 0;
}