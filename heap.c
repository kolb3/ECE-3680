#include "heap.h"
#include <stdlib.h>
#include <assert.h>

void Downward_Heapify(Heap_Type * H_Ptr, int start);
void Upward_Heapify(Heap_Type * H_Ptr);

Heap_Type * Heap(){
  //Pointer to new Heap Data Type
  Heap_Type * New_Heap_Ptr = NULL;
  New_Heap_Ptr = (Heap_Type *) malloc(sizeof(Heap_Type));
  if(New_Heap_Ptr == NULL){
    return NULL; //out of memory
  }

  //New heap is empty
  New_Heap_Ptr->Size = 0;

  //Reserve some space for the Heap
  New_Heap_Ptr->Max_Size = HEAP_INITIAL_MAX_SIZE;
  New_Heap_Ptr->Items = (Heap_Item_Type *) malloc(sizeof(Heap_Item_Type)*HEAP_INITIAL_MAX_SIZE);
  if(New_Heap_Ptr->Items == NULL)
  {
    New_Heap_Ptr->Max_Size =0;
    free(New_Heap_Ptr);
    return NULL; //out of memory
  }

  return New_Heap_Ptr;
}


Heap_Type * Heap_Create(Heap_Item_Type * New_Items, int size)
{
  //Pointer to new Heap Data Type
  Heap_Type * New_Heap_Ptr = NULL;
  New_Heap_Ptr = (Heap_Type *) malloc(sizeof(Heap_Type));
  if(New_Heap_Ptr == NULL){
    return NULL; //out of memory
  }

  //Reserve space for the items
  New_Heap_Ptr->Max_Size = size;
  New_Heap_Ptr->Items = (Heap_Item_Type *) malloc(sizeof(Heap_Item_Type)*size);
  if(New_Heap_Ptr->Items == NULL)
  {
    New_Heap_Ptr->Max_Size =0;
    free(New_Heap_Ptr);
    return NULL; //out of memory
  }
  New_Heap_Ptr->Size = size;

  //Copy items into HEAP
  for(int i=0;i<size;i++){
    New_Heap_Ptr->Items[i] = New_Items[i];
  }

  //Build HEAP
  for(int j= size-1; j<=0; j--){
    Downward_Heapify(New_Heap_Ptr,j);
  }

  return New_Heap_Ptr;

}
void Heap_Delete(Heap_Type * H_Ptr){
  //release the memory for the items in the dynamic array
  free(H_Ptr->Items);

  //reset variables just in case
  H_Ptr->Items = NULL;
  H_Ptr->Max_Size = 0;
  H_Ptr->Size = 0;

  //release the memory or the heap struct
  free(H_Ptr);
}


bool Heap_IsEmpty(Heap_Type *H_Ptr){
  return(H_Ptr->Size <= 0);
}


Heap_Item_Type Heap_GetMax(Heap_Type *H_Ptr){
  assert(Heap_IsEmpty(H_Ptr) == false);
  return(H_Ptr->Items[0]);
}


Heap_Item_Type Heap_RemoveMax(Heap_Type *H_Ptr)
{
  //Get Max
  Heap_Item_Type max_item = H_Ptr->Items[0];

  //Replace first item with last item
  H_Ptr->Items[0] = H_Ptr->Items[H_Ptr->Size-1];
  H_Ptr->Size--;

  //Downard_Heapify
  Downward_Heapify(H_Ptr,0);

  return max_item;
}

void Downward_Heapify(Heap_Type * H_Ptr, int start){
  if(H_Ptr->Size <= 0){
    return;
  }

  assert(start < H_Ptr->Size);
  Heap_Item_Type item_to_move_down = H_Ptr->Items[start];
  int i = start;
  int left_child = 2*i + 1;
  int right_child = 2*i + 2;

  while(left_child < H_Ptr->Size){
    int largest_child = left_child;
    if(right_child < H_Ptr->Size){
      if(H_Ptr->Items[right_child] > H_Ptr->Items[left_child]){
        largest_child = right_child;
      }
    }

    if(item_to_move_down >= H_Ptr->Items[largest_child]){
      break;
    } else {
      //move child up
      H_Ptr->Items[i] = H_Ptr->Items[largest_child];

      //move index Down
      i = largest_child;
      left_child = 2*i + 1;
      right_child = 2*i + 2;
    }
  }
  H_Ptr->Items[i] = item_to_move_down;
}

bool Heap_Insert(Heap_Type * H_Ptr, Heap_Item_Type Item)
{
  int New_Size;
  Heap_Item_Type * New_Items = NULL;
  if(H_Ptr->Size >= H_Ptr->Max_Size){
    New_Size = (int) (H_Ptr->Max_Size) * HEAP_GROW_RATE;
    if(New_Size <= H_Ptr->Max_Size){
      return false; //overflow
    }
    New_Items = (Heap_Item_Type *) realloc(H_Ptr->Items, sizeof(Heap_Item_Type) * New_Size);
    if(New_Items == NULL){
      return false;//out of memory
    }
    H_Ptr->Max_Size = New_Size;
    H_Ptr->Items = New_Items;
  }

  //insert into priority queue
  H_Ptr->Items[H_Ptr->Size] = Item;
  H_Ptr->Size++;

  //fix
  Upward_Heapify(H_Ptr);

  return true;
}

void Upward_Heapify(Heap_Type * H_Ptr){
  Heap_Item_Type new_item = H_Ptr->Items[H_Ptr->Size - 1];
  int child = H_Ptr->Size -1;
  int parent = (child-1)/2;
  while ((child >0) &&(H_Ptr->Items[parent])){
    //swap parent Down
    H_Ptr->Items[child] =H_Ptr->Items[parent];
    child = parent;
    parent = (child-1)/2;
  }

  //put new item in final position
  H_Ptr->Items[child] = new_item;
}
