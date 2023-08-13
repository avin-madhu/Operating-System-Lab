#include<stdio.h>
void main()
{
 int i,init,req[50],n,size,dir,j,temp,point,total=0;
 printf("Enter the number of requests\n");
 scanf("%d",&n);
 printf("Enter the request sequence\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&req[i]);
 }
 printf("Enter the disk size\n");
 scanf("%d",&size);
 size-=1;
 printf("Enter the initial disk position: \n");
 scanf("%d",&init);
 printf("Enter the direction of head!!(0 for left to right and any other for right to left)");
 scanf("%d",&dir); 
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(req[j]>req[j+1])
   {
    temp=req[j];
    req[j]=req[j+1];
    req[j+1]=temp;
   }
  }
 } 
 point=init;
 for(i=0;i<n;i++)
 {
  if(req[i]<point)
  {
   point=req[i];
   break;
  }
 }
 if(dir==0)
 {
   total=(size-init)+(size-point);
  }
  else
  {
   total=init+req[n-1];
  }
  printf("The total disk movement is %d\n",total);
 }