#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "sequence.h"
long *Generate_2p3q_Seq(int length, int *seq_size);
int sequenceHelp(int low, int high);

//PEER_REVIEW: Would like some help to see if the sequence is correct in order and correct in implementation. Used a helper function that calculates the held power and returns to be used to generate sequence back in the function.

int main()
{
    int n = 10;
    int arr = 0;

    long * numbers = Generate_2p3q_Seq(10, &arr);

    for(int i = 0; i<n; i++)
    {
        printf("%ld\n", numbers[i]);
    }

    return 0;
}


long *Generate_2p3q_Seq(int length, int *seq_size)
{
    int two;
    int max = 0;
    int first;
    int next = 0;
    int hold1;
    int hold2;
    int finale;
    long * k = malloc(sizeof(*k) * 1);
    //printf("problem?");


    if (length == 1 || length == 0)
    {
        return NULL;
    }

    for(two = 2; two < length; max++)
    {
        two = two * 2;
    }

    for (int x = 0; x < max; x++)
    {
        first = x;
        while(first != -1)
        {
            hold1 = sequenceHelp(2, first);
            hold2 = sequenceHelp(3, next);
            finale = first * next;

            if(finale >= length)
            {
                break;
            }
            else
            {
                if(*seq_size == 0)
                {
                    //printf("problem?");
                    k[*seq_size] = finale;
                }
                else{
                    //printf("problem?");
                    k = realloc(k, sizeof(*k) * (*seq_size + 1)); //reallocate k based on the new intil sequence;
                    k[*seq_size] = finale;
                }
                (*seq_size)++;
                next += 1;
                first -= 1;
            }
        }
    }
    return k;
}

int sequenceHelp(int low, int high)
{
    int count;
    int check;
    if(high != 0)
    {
        //printf("problem?");
        count = 1;
        while(count <= high)
        {
            check = check * low;
            count++;
        }
    }
    else
    {
        check = 1;
        return check;
    }
    return check;
}
