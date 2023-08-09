#include <stdio.h>

int writing = 0; // none is writing at the start
int reading = 0; // none is reading at the start
int readerCount = 0; // checks number of readers
int mutex = 1;

void read()
{
    mutex=0;
    reading = 1;
    readerCount++;
    printf("\nReader(%d) is reading...\n", readerCount);
    mutex=1;

}

void write()
{
    mutex=0;
    writing = 1;
    printf("\nWriter(%d) is writing...\n", writing);
    mutex=1;
}


int main()
{
     int choice;

    do 
   {
      printf("\n\n     SELECT OPERATION\n-----------------------------\n1) Read\n2) Write\n3) delete last reader\n4) delete last writer\n5) Exit");
      printf("\n-----------------------------\nEnter your choice: ");
      scanf("%d", &choice);

      if(choice == 1) // read 
      {
          if(writing == 0&&mutex==1)
          {
            read();
          }
          else
          {
           printf("\nCannot read, A writer is currently writing...\n");
          }  
      }
      else if (choice == 2) // write
      {

         if(reading == 0 && mutex==1 && writing== 0)
         {
            write();
         }
         else if(writing == 1)
         {
            printf("\nCannot write, A writer is currently writing...\n");
         }
         else
         {
            printf("\nCannot write, A Reader is currently reading...\n");
         }
      }
      else if (choice == 3)
      {
         if(readerCount == 0)
         {
            printf("\n No Readers are reading !\n");
         }
         else
         {
            printf("\nA reader(%d) is removed\n",readerCount);
            readerCount--;
            if(readerCount == 0)
            {
               reading=0;
            }
         }
      }
      else if (choice == 4)
      {
         if(writing==0)
         {
            printf("\ncurrently none is writing..\n");
         }
         else
         {
             printf("\nThe writer is removed!\n");
             writing=0;
         }
      }
     else if (choice == 5)
     {
        printf("\n Exiting code ...\n\n");
     }
     
   }while(choice != 5);
}