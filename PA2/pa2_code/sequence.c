#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

long * Generate_2p3q_Seq(int length, int * seq_size)
{
  int ct,i,p,q = 0;
  int dexi;
  int phold,qhold;
  long * key = NULL;
  long * newkey = NULL;
  long temp;
  int count = 0;

  key = malloc(length * sizeof(long));
  if(key == NULL)
  {
    *seq_size = 0;
    return NULL;
  }

  phold = quot(length,2); //changed from power function
  qhold = quot(length,3); //changed from power function
//printf("%d, %d\n",phold,qhold);
  for(ct = 0; ct <= phold; ct++)
  {
    for(i = 0; i <= qhold; i++)
    {
      p = exponent(2,ct);  //changed from power function
      q = exponent(3,i);   //changed from power function
      temp = (long)p * (long)q;
//printf("%ld\n",temp);
//printf("%d\n",length);
      dexi = noexist(temp, count, key);
//printf("%d,  %ld\n",dexi, temp);
      if(dexi && (temp < length) && (temp >= 0))
      {
        key[count] = temp;
        count++;
      }

    }
  }
  //printf("%d\n",count);
  newkey = calloc(count, sizeof(long));
  for(int t = 0; t< count; t++)
  {
	newkey[t] = key[t];
  }
  
  /*for(int t = 0; t< count; t++)
  {
	printf("%ld\n",key[t]);
  }*/

  free(key);
  *seq_size = count-1;
  sort(newkey, *seq_size);
  /*for(int t = 0; t< count; t++)
  {
	printf("%ld\n",newkey[t]);
  }*/
  return newkey;

}

//new function to find the exponent number needed
int quot(int a, int b)
{
	int ans = 0;
	while(a != 0)
	{
		a /= b;
		ans++;
	}
	return ans;
}

//new function to find answer after power
int exponent(int a, int b)
{
	int ans = 1;
	for(int i = 0; i < b; i++)
	{
		ans *= a;
	}
	return ans;
}

int noexist(long comp, int size, long * arr)
{
  int ct;
  if(size == 0)
  {
    return 1;
  }
  for(ct = 0; ct < size; ct++)//while(ct <= size)
  {
    if(comp == arr[ct])
    {
      return 0;
    }
  
  }
  return 1;
}// should check to see if the number is already in the array if it is then returns false else returns true
//and then it should run the reallocate part and save the new value


void sort(long * key, int count)
{
  long temp;
  if(count < 1)
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
