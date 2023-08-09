#include <stdio.h>
struct file
{
    char fname[10];
    int start,size,block[10];
}f[10];

int main()
{
     int n;
     printf("Enter the number of files: ");
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
        printf("Enter the file name for file-%d: ",i+1);
        scanf("%s",&f[i].fname);
        printf("Enter the starting block: ");
        scanf("%d",&f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter the number of blocks: ");
        scanf("%d",&f[i].size);
        printf("Enter the allocated blocks: ");
        for(int j=1;j<=f[i].size;j++)
        {
            scanf("%d",&f[i].block[j]);
        }
     }
        printf("\nFilename\tstart\tsize\tBlocks\n");

        for(int i=0;i<n;i++)
        {
            printf("%s\t%d\t%d\t",f[i].fname,f[i].start,f[i].size);
            for(int j=1;j<=f[i].size-1;j++)
            {
                printf("%d->",f[i].block[j]);
            }
            printf("%d",f[i].block[f[i].size]);
            printf("\n");
        }
}