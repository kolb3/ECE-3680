#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "shell_array.h"
#include "shell_list.h"
#include "sequence.h"

//PEER REVIEW: List does not work, array is somewhat functional, not all tests finished.

void printList(Node * head);
void printArr(long * arr, int size);
void nodeFree(Node ** head);

int main(int argc, char ** argv)
{
  if (argc != 4)
    {
      return EXIT_FAILURE; 
    }

  char *letterA = "-a";
  char *letterL = "-l";

  if(strcmp(argv[1],letterA) == 0)
    {
      int size = 0;
      double n_comp = 0;
      int hold;
      long * arr = Array_Load_From_File(argv[2],&size);

      if (arr == NULL)
        {
       	  return EXIT_FAILURE;
        }

      if (size == 0)
        { 
          hold = Array_Save_To_File(argv[3],arr,size);
          n_comp = 0;
        } 
      else
        {
          Array_Shellsort(arr, size, &n_comp);
          hold = Array_Save_To_File(argv[3],arr,size);
	    }

      printf("%f\n",n_comp);
 
      if (hold != size)
        { 
	        exit(EXIT_FAILURE);
        }

    //   printArr(arr, size);

      free(arr);
    }
		
    else if(strcmp(argv[1],letterL) == 0)
       {
           double n_comp = 0;
           Node * head = List_Load_From_File(argv[2]);
           head = List_Shellsort(head,&n_comp);
           List_Save_To_File(argv[3],head);
           nodeFree(&head);
       }
    return EXIT_SUCCESS;
}

void printArr(long * arr, int size)
{
  int i;
  for (i = 0; i < size; i++)
    {
      printf("value: %ld\n", arr[i]);
    }
	
}

void printList(Node * head)
{
  Node * p = head;
  printf("printlistnode: ");
  while (p != NULL)
    {
      printf("%ld\n", p -> value);
      p = p -> next;
    }
}

void nodeFree(Node ** head)
{
  Node * current = (*head); 
  Node * next; 
  while (current != NULL)  
    { 
       next = current -> next; 
       free(current); 
       current = next; 
    }
   *head = NULL;
}
