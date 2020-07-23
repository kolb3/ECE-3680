#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"


//Well hopefully I can update this because of a shitty fluke with GITHUHB DESKTOP all of my work got deleted, so as of rightn ow I have nothing which is bullshit so below are my questions that I had previously asked hopefully this will make life a lot easier
//in main we call the open file which saves everything and returns the adress of a long int, then we call a sort which calls generate, this is where my questions start
//the n_comp variable is that supposed to be passed by address purely so we can count the number of times things have been evaluated?
//the other question I have is on the generate function, am I just supposed to create a pratt gap sequence of elements that are less than n, n being the totall number of elements from the file?
//then this array of gap sequence elements 1,2,3,4,6,8,9 etc are supposed to be set as longs and then those will give us the key k for the shells in the shell sort.
int main(int argc, char * * argv)
{
  int num = 0;
  double comp = 0;
  long * arr = NULL;

  //printf("%d\n",argc);
  //printf("%s, %s\n", argv[2],argv[3]);
  if(argc <= 3)
	{
		fprintf(stderr, "need 4 inputs\n");
		return EXIT_FAILURE;
	}


  if(strcmp(argv[1],"-a") == 0)
  {
	//printf("made it in -a\n");
    arr = Array_Load_From_File(argv[2], &num);
    if(num == 0)
    {
      Array_Save_To_File(argv[3], arr, num);
      return EXIT_SUCCESS;
    }
    Array_Shellsort(arr,num,&comp);
//printf("made it through the sort\n");
    Array_Save_To_File(argv[3], arr, num);
    printf("%le\n", comp);

    return EXIT_SUCCESS;

  }
  if(strcmp(argv[1],"-l") == 0)
  {
    return EXIT_SUCCESS;
  }
  else
  {
    fprintf(stderr, "need to know if array or linked list\n");
    return EXIT_FAILURE;
  }


}
