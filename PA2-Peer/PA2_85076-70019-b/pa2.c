#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequence.h"
#include "shell_array.h"
#include "shell_list.h"

int main (int argc, char * argv[])
{
    // Local Declarations
    int size = 0;
    double n_comp = 0;
    
    // Statements
    if (argc != 4)
        return EXIT_FAILURE;
    if (strncmp("-a", argv[1], 2) == 0)
    {
        long* arr = Array_Load_From_File(argv[2], &size);
        if (size == 0)
        {
            Array_Save_To_File(argv[3], arr, size);
            free(arr);
            return EXIT_SUCCESS;
        }   // if
        Array_Shellsort(arr, size, &n_comp);
        Array_Save_To_File(argv[3], arr, size);
        free(arr);
        return EXIT_SUCCESS;
    }   // if
    else if (strncmp("-l", argv[1], 2) == 0)
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
    return 0;
}