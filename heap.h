#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stdio.h>

#define HEAP_INITIAL_MAX_SIZE 4
#define HEAP_GROW_RATE 2
typedef int Heap_Item_Type;

//declare heap structure
struct Heap{
  int Size;
  int Max_Size;
  Heap_Item_Type *Items;
};

typedef struct Heap Heap_Type;

//function prototypes
Heap_Type * Heap();
Heap_Type * Heap_Create(Heap_Item_Type * New_Items, int size);
void Heap_Delete(Heap_Type * H_Ptr);
bool Heap_IsEmpty(Heap_Type *H_Ptr);
Heap_Item_Type Heap_GetMax(Heap_Type *H_Ptr);
Heap_Item_Type Heap_RemoveMax(Heap_Type *H_Ptr);
bool Heap_Insert(Heap_Type * H_Ptr, Heap_Item_Type Item);

#endif //Heap H
