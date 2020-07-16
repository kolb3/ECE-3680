#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_array.h"
#include "sequence.h"



long *Array_Load_From_File(char *filename, int *size) 
{
  int count = 0;
  long sauce = 0;
  FILE * here = fopen(filename, "rb");
  if(here == NULL)
    {
      fclose(here);
      return 0;
    }

  fseek(here, 0, SEEK_SET);

  while(feof(here) == 0)
    {
      if(fread(&sauce, sizeof(long), 1, here) != 1)
        {
          break;
        }
      else
        {
           count = count + 1;
        }
    }

  fclose(here);

  *size = count;

  long * mode = NULL;

  if (*size == 0) 
    { 
      mode = malloc(sizeof(long) * 0);
        if(mode == NULL)
          {
            printf("bad\n");
            return NULL;
          }
           return mode;
    }

  mode = malloc(sizeof(long)*(*size));

  if(mode == NULL)
    {
      printf("bad\n");
      return NULL;
      //printf("problem?");
    }

  sauce = 0;
  int x = 0;
  here = fopen(filename, "rb");
  if(here == NULL)
    {
      fclose(here);
    }

  fseek(here, 0, SEEK_SET);

  while(feof(here) == 0)
    {
      if(fread(&sauce, sizeof(long), 1, here) != 1)
        {
          break;
        }
      else
        {
          mode[x] = sauce;
          //printf("problem?");
        }
      x++;
    }

  fclose(here);
  return mode;
}

int Array_Save_To_File(char *filename, long *array, int size) 
{
  FILE * here = fopen(filename,"wb");

  if (here == NULL) 
    {
      return 0;
    }

  if (size == 0) 
    {
      return 0;
    }

  int x = 0;
  int counter = 0;
  //printf("problem?");

  for(x = 0; x < size; x++) 
    {
      if(fwrite(&array[x], sizeof(array[x]), 1, here) != 1)
        { 
            //printf("problem?");
          printf("did not save\n");  
        }
      counter += 1;
    }

  fclose(here);
  return counter;
}

void Array_Shellsort(long *array, int size, double *n_comp)
{
  int x = 0;
  int y = 0;
  int z = 0;
  int hold;
  int redo = 0;
  int finale = 0;
  int mode = size - 1;
  long * k = Generate_2p3q_Seq(size, &finale);
  //printf("problem?");

  for (x = finale - 1; x >= 0; x = x - 1)
  {
      y = k[x];
      redo = y;
      while (z <= mode)
      //printf("problem?");
      {
          int temp = array[redo];
          hold = redo;
          for (; array[hold - y] > temp && hold > y; hold = hold - y)
          {
              //printf("problem?");
              (*n_comp)++;
              array[hold] = array[hold - y];
          }
          array[hold] = temp;
      }

  }
  free(k);
}

