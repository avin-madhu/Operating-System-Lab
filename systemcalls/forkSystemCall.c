// to demonstrate the use of fork system call 

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>

int main()
{
    int check=0;

    check = fork();

    if(check>0) // parent process (positive number)
    {
        int id = getpid();
        printf("parent id: %d\n", id);
    }
    else if(check==0)// child process (zero)
    {
        int childid = getpid();
        printf("child id: %d\n", childid);
    }

}