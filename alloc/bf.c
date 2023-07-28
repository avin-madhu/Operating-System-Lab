#include <stdio.h>
int main()
{
   int block[50], //for storing the block size
       data[50], // for storing the data size
       nb,nd, // for storing the number of data and blocks respectivey 
       temp,  // for storing the fragment temporarily 
       b_order[50], // for storing the order of allocation of blocks
       fragments[50],
       allocated[50];// for storing the smallest block
   printf("Enter the number of blocks: ");
   scanf("%d",&nb);
   printf("Enter the block Sizes: \n");
   for(int i=0;i<nb;i++)
   {
     printf("Block %d: ",i+1);
     scanf("%d",&block[i]);
   }

   int smallest = block[0];

   printf("Enter the number of data: ");
   scanf("%d",&nd);
   printf("Enter the data Sizes: \n");
   for(int i=0;i<nd;i++)
   {
     printf("Data %d: ",i+1);
     scanf("%d",&data[i]);
   }

   for(int i=0;i<nd;i++)
   {
      for(int j=0;j<nb;j++)
      {
        if(allocated[i]!=1)
        {
            int k=0;
            while(block[k]<smallest&&k<=nb)
            {
               smallest = block[k];
               k++;
            }
            
            

        }
      }
   }
}