#include <stdio.h>
int main()
{
    int n,sb[10],s[10],m[10],b[10][10],x;
    
    printf("Enter the number of files: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Enter the starting block and size of file-%d",i+1);
        scanf("%d %d", &sb[i], &s[i]);
        printf("Enter the blocks occupied by file-%d",i+1);
        scanf("%d",&m[i]);
        printf("Enter the blocks of file-%d",i+1);
        for(int j = 0; j < m[i]; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    printf("\nFile\tIndex\tSize\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n",i+1,sb[i],m[i]);
    }
    printf("Enter the file name: ");
    scanf("%d",&x);
    printf("\nThe file name: %d\n",x);
    printf("The File index: %d\n",sb[x-1]);
    printf("The File size: %d\n",m[x-1]);
    printf("The blocks occupied are: ");
    for(int j=0;j<m[x-1];j++)
    {
        printf("%d ",b[x-1][j]);
    }

}