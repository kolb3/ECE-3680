#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_INITIAL_MAX_SIZE 64
#define STACK_GROW_RATE 2
typedef int Stack_Item_Type;

//declare stack structure
struct STack{
  int Top;
  int Max_Size;
  Stack_Item_Type * Items;
};

typedef struct Stack Stack_Type;

//function prototypes
Stack_Type * Stack_New();
void Stack_Delete(Stack_Type * S_Ptr);
bool Stack_IsEmpty(Stack_Type * S_Ptr);
Stack_Item_Type Stack_Top(Stack_Type * S_Ptr);
Stack_Item_Type Stack_Pop(Stack_Type * S_Ptr);
bool Stack_Push(Stack_Type * S_Ptr, Stack_Item_Type Item);

#endif //STACK_H
