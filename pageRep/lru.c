#include<stdio.h>
int n,rs[30],f,m[10],count=0,pf=0,least[10],flag,temp,pos,i,j,k;
void main()
{
    printf("\nEnter the length of the page string:");
    scanf("%d",&n);
    printf("\nEnter the reference page string:");
    for(int i=0;i<n;i++)
        scanf("%d",&rs[i]);
    printf("\nEnter the number of frames:");
    scanf("%d",&f);

    for(int i=0;i<f;i++)//Initialising all frames with -1
      m[i]=-1;  
      
      printf("-----LRU Page Replacement Algorithm is:\n----");

      for(i=0;i<n;i++)
      {
        flag=0;
        for(j=0;j<f;j++)
        {
            if(m[j]==rs[i])//hit
            {
                flag=1;
                break;
            }
        }
        if(flag==0)//page fault
        {
            if(count<f)
            {
                m[count++]=rs[i];
                pf++;//fill available frames
            }
            else{
                for(j=0;j<f;j++)
                {
                  least[j]=0;
                  for(k=i-1;k>=0;k--)
                  {
                    if(m[j]==rs[k]){
                        least[j]=i-k;
                        break;
                    }
                  }
                }
                pos=0;
                for(j=1;j<f;j++){
                    if(least[j]>least[pos]){
                        pos=j;//least recently used or with most age among the frames
                    }
                }
                m[pos]=rs[i];//allocating page to frame by overwriting the lest recently used page
                pf++;
            }
        }
        for(j=0;j<f;j++)
        {
            if(m[j]==-1)
               printf("\t_");
            else
                printf("\t%d",m[j]);
        }
        if(flag==0){
            printf("\tMiss");
        }
        printf("\n");
    }
     printf("\nThe number of page faults:%d",pf);
     printf("\nthe number of hits:%d",n-pf);
}