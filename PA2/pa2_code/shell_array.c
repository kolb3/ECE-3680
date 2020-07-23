#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"


long *Array_Load_From_File(char *filename, int *size)
{
  int ct;
  long * input = NULL;

  FILE * fptr = fopen(filename, "rb");
  if(fptr == NULL)
  {
    fprintf(stderr, "fopen did not work\n");
    return NULL;
  }

  fseek(fptr,0,SEEK_END);
  *size = ftell(fptr);
  ct = *size;
  *size = *size/sizeof(long);
  fseek(fptr,0,SEEK_SET);

  if(ct % sizeof(long) != 0)
  {
    fclose(fptr);
    exit(EXIT_FAILURE);
  }

  input = malloc(sizeof(long) * *size);

  for(ct = 0; ct < *size; ct++)
  {
    if(fread(&input[ct], sizeof(long),1,fptr) != 1)
	break;
  }

  fclose(fptr);
  return input;

}

int Array_Save_To_File(char *filename, long *array, int size)
{
  int ct;

  FILE * fptr = fopen(filename, "wb");
  
  //printf("%s\n",filename);
  
  for(ct = 0; ct < size; ct++)
  {
    fwrite(&array[ct], sizeof(long), 1, fptr);
  }
  fclose(fptr);
  return ct;
}

void Array_Shellsort(long *array, int size, double *n_comp)
{
  int ct=0; //seq size in Generate_2p3q_Seq
  long * key = NULL; //array of shell sort numbers
  long count, hold, temp, diff; // different holder variables for moving around

  key = Generate_2p3q_Seq(size, &ct);
 //printf("%ld\n",key[ct]);

  while(ct >= 0)
  {
    diff = key[ct];
    for(count = diff; count < size; count++)
    {
      temp = array[count];
      hold = count - diff;
      while(hold >= 0 && (temp < array[hold]))
      {
        array[hold + diff] = array[hold];
        hold -= diff;
      }
      array[hold + diff] = temp;
      (*n_comp)++;
    }
    ct--;
  }
  free(key);
}
