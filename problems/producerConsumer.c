// Producer Consumer Problem 

#include <stdio.h>

int mutex = 0; // for mutual exclusion 
int full = 0;// false initially
int empty = 1; // true initally
int bufferSize;
int items=0; // to keep count of the number of items



void producer()
{
  mutex = 1;
  empty = 0;
  items++;
  printf("\nproducer produced item-%d", items);
  if(items == bufferSize)
  {
    full = 1; // buffer is full
  }
   mutex = 0;
}

void consumer()
{
  mutex = 1;
  full = 0;
  printf("\nconsumer consumed item-%d \n", items);
  items--;
  if(items == 0)
  {
    empty = 1; // buffer is full
  }
   mutex = 0;
}

int main()
{
   printf("Enter the buffer size: ");
   scanf("%d", &bufferSize);
   int choice;
   do 
   {
      printf("\n\n     SELECT OPERATION\n-----------------------------\n1) produce an item\n2) consume an item\n3) Check if full\n4) Check if empty\n5) Exit");
      printf("\n-----------------------------\nEnter your choice: ");
      scanf("%d", &choice);
      if (choice == 1&& mutex == 0)
      {
        if(full == 0)
        {
            producer();
        }
        else
        {
            printf("\n The buffer is full!\n"); 
        }
      }
      else if (choice == 2 && mutex == 0)
      {
        if(empty == 0)
        {
            consumer();
        }
        else
        {
            printf("\n The buffer is empty!\n");
        }
      }
      else if (choice == 3)
      {
         if(full == 1)
         {
            printf("\n The buffer is full!\n");
         }
         else
         {
            printf("\n The buffer has more space..\n");
         }
      }
      else if (choice == 4)
      {
         if(empty == 1)
         {
            printf("\n The buffer is empty!\n");
         }
         else
         {
            printf("\n The buffer has more items..\n");
         }
      }
      else if(choice == 5)
      {
        printf("\n Exiting code...\n\n");
      }
   }while(choice != 5);
}