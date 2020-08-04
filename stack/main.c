#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
  //Get a point to a new stack (empty)
  Stack_Type * Stack_Ptr = Stack_New();

  //How many items to run this example for
  int num_items = 100;

  bool success = false;

  //Push num_items onto stack (in this case just integers 0 through numitems-1)
  for(int i = 0; i < num_items; i++)
  {
    success = Stack_Push(Stack_Ptr,i);
    if(success){
      printf("Pushed item %d\n",i);
    }else {
      printf("Error. Push failed.\n");
      break; //Stop pushing.
    }
  }

  //Pop the top off the stack, and keep popping until it's empty
  if(success){
    int item;
    while(!Stack_IsEmpty(Stack_Ptr)){
      item = Stack_Pop(Stack_Ptr);
      printf("Popped item: %d\n",item);
    }
  }

  //Delete the stack(good coding practice)
  Stack_Delete(Stack_Ptr);
  return 0;
}
