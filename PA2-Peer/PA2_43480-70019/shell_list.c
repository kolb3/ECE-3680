#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_list.h"
#include "sequence.h"

static Node * nodeCreate(long value);
static int nodeCount(Node ** head);
static void nodeAppend(Node ** head, long value);
// static long nodeIndVal(Node ** seq, int val);
// static void nodeChange(Node ** head, int x, int y);

static Node * nodeCreate(long value) 
{
  Node * lnode = malloc(sizeof(Node));
  lnode -> next = NULL;
  lnode -> value = value;
  return lnode;
}

static int nodeCount(Node ** head) 
{
  Node * hold = *head;
  int node_hold = 0;

  while (hold != NULL)
    {  
      hold = hold -> next; 
      node_hold = node_hold + 1;  
    }

  return node_hold;
}

static void nodeAppend(Node ** head, long value) 
{
  Node * nodeNew = nodeCreate(value);
  Node * hold = *head;

  while (hold -> next != NULL) 
    {
      hold = hold -> next;
    }
  hold -> next = nodeNew;
  return;
}

// static long nodeIndVal(Node ** seq, int value) 
// {
//   Node * hold = *seq;
//   int x = 0;

//   while (x != value) 
//     {
//       hold = hold -> next;
//       x = x + 1;
//     }
	
//   return hold -> value;
// }

// static void nodeChange(Node ** head, int x, int y) 
// {
//   int count = 0;

//   Node * xhold = *head;
//   Node * yhold = *head;
//   Node * xholdp = NULL;
//   Node * yholdp = NULL;


//   while (count < x) 
//     {
//       xholdp = xhold;
//       xhold = xhold -> next;
//       count = count + 1;
//     }

//   count = 0;

//   while (count < y) 
//     {
//       yholdp = yhold;
//       yhold = yhold -> next;
//       count = count + 1;
//     }

//   if (xholdp != NULL) 
//     {
//       xholdp -> next = yhold;
//     }
//   else 
//     {
//       *head = yhold;
//     }

//   if (yholdp != NULL) 
//     {
//       yholdp -> next = xhold;
//     }
//   else 
//     {
//       *head = xhold;
//     }

//   Node * hold = yhold -> next;
//   yhold -> next = xhold -> next;
//   xhold -> next = hold;

//   return;
// }

Node * List_Load_From_File(char * filename) 
{
  long hold = 0;
  FILE * here = fopen(filename, "rb");
  if (here == NULL) 
    {
      fclose(here);
      return NULL;
    }

  fseek(here, 0, SEEK_SET);

  Node * start = NULL;

  if (fread(&hold, sizeof(long), 1, here) != 1) 
    {
    }
  else 
    {
      start = nodeCreate(hold);
    }

  while(feof(here) == 0) 
    {
      if (fread(&hold, sizeof(long), 1, here) != 1) 
        {
        }
      else 
        {
          nodeAppend(&start, hold);
        }
    }
  
  fclose(here);
  return start;
}

int List_Save_To_File(char * filename, Node * list) 
{
  FILE * here = fopen(filename,"wb");
  if(here == NULL)
    {
      exit(EXIT_FAILURE);
    }
  int size = nodeCount(&list);
  Node * hold = list;
  int count = 0;

  for(int i = 0; i < size; i++)
    {
      count+= fwrite(&hold -> value, sizeof(long int), 1, here);
      hold = hold -> next;
    }
  if(count != size)
    {
      exit(EXIT_FAILURE);
    }

  fclose(here);
  return count;
}

//PEER_REVIEW: although this is extra credit would benefit if i could be pointed in the right direction, had confusion on how to start and implement the function.

Node *List_Shellsort(Node *list, double *n_comp)
{

    return NULL;
}
