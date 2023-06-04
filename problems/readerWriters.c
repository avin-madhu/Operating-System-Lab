#include <stdio.h>

int writing = 0; // none is writing at the start
int readerCount = 0;
int writerCount = 0;

void read()
{
    readerCount++;
    printf("\nReader(%d) is reading...\n", readerCount);
}

void write()
{
    writing = 1;
    writerCount++;
    printf("\nWriter(%d) is writing...\n", writerCount);
}


int main()
{
     int choice;

    do 
   {
      printf("\n\n     SELECT OPERATION\n-----------------------------\n1) Read\n2) Write\n3) delete last reader\n4) delete last writer\n5) Exit");
      printf("\n-----------------------------\nEnter your choice: ");
      scanf("%d", &choice);
      if(choice == 1)
      {
          if(writing == 0)
          {
            read();
          }
          else
          {
           printf("\nCannot read, A writer is currently writing...\n");
          }  
      }
      else if (choice == 2)
      {
        write();
      }
      else if (choice == 3)
      {
         
         printf("\nA reader(%d) is removed\n",readerCount);
         readerCount--;
      }
      else if (choice == 4)
      {
         
         printf("\nA writer(%d) is removed\n",writerCount);
         writerCount--;
         if(writerCount==0)
         {
            printf("\ncurrently none is writing..\n");
            writing=0;
         }
      }
     else if (choice == 5)
     {
        printf("\n Exiting code ...\n\n");
     }
     
   }while(choice != 5);
}