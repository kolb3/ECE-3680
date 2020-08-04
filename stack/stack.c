#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

Stack_Type * Stack_New()
{
  //Pointer to new "Stack Data Type"
  Stack_Type *New_Stack_Ptr = NULL;
  New_Stack_Ptr = (Stack_Type *) malloc(sizeof(Stack_Type));
  if(New_Stack_Ptr == NULL)
  {
    return NULL; //out of memory
  }

  //New stack is Stack_IsEmpty
  New_Stack_Ptr->Top = -1;

  //Reserve some space for the stack
  New_Stack_Ptr->Max_Size = STACK_INITIAL_MAX_SIZE;
  New_Stack_Ptr->Items = (Stack_Item_Type *) malloc(sizeof(Stack_Item_Type) * STACK_INITIAL_MAX_SIZE);
  if(New_Stack_Ptr->Items == NULL)
  {
    New_Stack_Ptr->Max_Size = 0;
    free(New_Stack_Ptr);
    return NULL;
  }
  return New_Stack_Ptr;
}


void Stack_Delete(Stack_Type * S_Ptr)
{
  //release the memory for the items in the dynamic array
  free(S_Ptr->Items);

  //reset variables just in case
  S_Ptr->Items = NULL;
  S_Ptr->Max_Size = 0;
  S_Ptr->Top = -1;

  //relese the memory for the stack structure
  free(S_Ptr);
}


bool Stack_IsEmpty(Stack_Type * S_Ptr)
{return(S_Ptr->Top < 0);

}


Stack_Item_Type Stack_Top(Stack_Type * S_Ptr)
{
  assert(S_Ptr->Top >= 0);
  return(S_Ptr->Items[S_Ptr->Top]);
}


Stack_Item_Type Stack_Pop(Stack_Type * S_Ptr)
{
  assert(S_Ptr->Top >= 0);
  Stack_Item_Type Result = S_Ptr->Items[S_Ptr->Top];
  S_Ptr->Top--;
  return(Result);
}

bool Stack_Push(Stack_Type * S_Ptr, Stack_Item_Type Item)
{
  //resize if needed
  int New_Size;
  Stack_Item_Type * New_Items = NULL;
  if(S_Ptr->Top + 1 >= S_Ptr->Max_Size)
  {
    New_Size = (int) (S_Ptr->Max_Size * STACK_GROW_RATE);
    if(New_Size <= S_Ptr->Max_Size)
    {
      return false; //overflow
    }
    New_Items = (Stack_Item_Type *) realloc(S_Ptr->Items, sizeof(Stack_Item_Type) * New_Size);
    if(New_Items == NULL)
    {
      return false; //out of memory
    }
    S_Ptr->Max_Size = New_Size;
    S_Ptr->Items = New_Items;
  }
  //push onto stack
  S_Ptr->Top++;
  S_Ptr->Items[S_Ptr->Top] = Item;
  return true;
}
