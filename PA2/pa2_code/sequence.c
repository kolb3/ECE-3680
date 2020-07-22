#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

long * Generate_2p3q_Seq(int length, int * seq_size)
{
  int ct,i = 0
  int dexi;
  int phold,qhold;
  long * key = NULL
  long temp;
  *seq_size = 0;

  key = malloc(sizeof(long));
  if(key == NULL)
  {
    return NULL;
  }

  phold = floor(length ** (1/2));
  qhold = floor(length ** (1/3));

  for(ct = 0; ct <= phold; ct++)
  {
    for(i = 0; i <= qhold; i++)
    {
      temp = (2**ct)*(3**i);
      dexi = noexist(temp, *seq_size, &key);
      if(dexi && temp < length)
      {
        if(key[*seq_size] == NULL //this should reallocate the memory and allow to add one more
        {
          key = realloc(key, sizeof(long));
        }
        key[*seq_size] = temp
        *seq_size++;
      }

    }
  }
  *seq_size--;
  key = quicksort(key, *seq_size);
  return seq_size;

}


bool noexist(int comp, int size, long * arr)
{
  int ct = 0;
  while(ct <= size)
  {
    if(temp = arr[ct])
    {
      return false;
    }
  }
  return true;
}// should check to see if the number is already in the array if it is then returns false else returns true
//and then it should run the reallocate part and save the new value


void sort(long * key, int count)
{
  long temp;
  if(count <= 1)
  {
    return;
  }
  for(int i = 0; i<count; i++)
  {
    if(key[i] > key[i+1])
    {
      temp = key[i];
      key[i] = key[i+1];
      key[i+1] = temp;
    }
  }
  sort(key,count-1);

}//just a quick bubble sort to make sure everything is in order
