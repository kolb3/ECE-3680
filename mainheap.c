#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){

  //create empty Heap
  Heap_Type * my_heap;
  my_heap = Heap();

  //Add several random numbers
  int num_samples = 20;
  bool success = true;

  for(int i=0; i < num_samples; i++)
  {
    int new_item = rand()%100;
    printf("Adding item: %d\n",new_item);
    success = Heap_Insert(my_heap, new_item);
    if(success == false){
      printf("Error adding item.\n");
      return 1;
    }
  }

  //Remove the max for all items
  for(int i = 0; i< num_samples;i++){
    int extracted_item = Heap_RemoveMax(my_heap);
    printf("Removed item: %d\n", extracted_item);
  }

  //Delete Heap
  Heap_Delete(my_heap);
  return 0;
}
