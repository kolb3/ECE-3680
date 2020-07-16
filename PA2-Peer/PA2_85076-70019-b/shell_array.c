#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell_array.h"
#include "sequence.h"

long* Array_Load_From_File (char* filename, int* size)
{
    // Local Declarations
    int i, f;
    FILE* fp;

    // Statements
    fp = fopen (filename, "rb");
    if (fp == NULL)
    {
        *size = 0;
        return NULL;
    }   // if
    fseek (fp, 0, SEEK_END);
    *size = f = ftell(fp);
    fseek (fp, 0, SEEK_SET);
    *size = *size / (sizeof (long));
    if ((f % sizeof (long)) != 0)
    {
        // printf("Invalid file! File size is not a multiple of size of long:\n");
        // printf("size %d\n", f);
        // printf("long %ld\n", sizeof(long));
        fclose(fp);
        exit(EXIT_FAILURE);
    }   // if
    long* arr = (long*) malloc (*size * sizeof (long));
    for (i = 0; i < *size; i++)
    {
        if (fread (&arr[i], sizeof (long), 1, fp) != 1)
            break;
        // Used to debug inputs
        // printf ("arr[%d] = %li\n", i, arr[i]);
    }   // for
    fclose (fp);
    return arr;
}   // Array_Load_From_File

int Array_Save_To_File (char* filename, long* array, int size)
{
    // Local Declarations
    int i;
    FILE* fp;

    // Statements
    fp = fopen (filename, "wb");
    for (i = 0; i < size; i++)
        fwrite (&array[i], sizeof (long), 1, fp);
    fclose (fp);
    return i;
}   // Array_Save_To_File

void Array_Shellsort(long* array, int size, double* n_comp)
{
    // Local Declarations
    int seq_size;
    long gap, i, j, temp;
    long* sequence = Generate_2p3q_Seq (size, &seq_size);
    
    // Statements
    while (seq_size >= 0)
    {
        gap = sequence[seq_size];
        for (j = gap; j < size; j++)
        {
            temp = array[j];
            i = j - gap;
            while (i >= 0 && temp < array[i])
            {
                array[i + gap] = array[i];
                i = i - gap;
            }   // while
            array[i + gap] = temp;
            (*n_comp)++;
        }   // for
        seq_size--;
    }   // while 
    free (sequence);
    printf ("%e\n", *n_comp);
}   // Array_Shellsort