#include <stdio.h>
int main()
{
    int n,b[10],sb[10],t[10],c[10][10],x;

    printf("Enter the number of files: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
       printf("Enter the number of blocks for file-%d: ",i+1);
       scanf("%d", &b[i]);
       printf("Enter the starting block of file-%d: ",i+1);
       scanf("%d", &sb[i]);
       t[i] = sb[i];
       for(int j = 0; j <b[i];j++)
       {
          c[i][j] = sb[i]++;
       }
    }
    
    printf("Filename\tStartBlock\tLength\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\n",i+1,t[i],b[i]);
    }
    printf("Enter the file name: ");
    scanf("%d",&x);

    printf("\n\nFile name: %d\n",x);
    printf("File length: %d\n",b[x-1]);
    printf("The blocks allocated: ");
    for(int i=0;i<b[x-1];i++)
    {
        printf("%d ",c[x-1][i]);
    }



}