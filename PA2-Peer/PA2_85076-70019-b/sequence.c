#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

static double myFloor (double x)
{
    // Local Declarations
    double temp = (double) (int) x;
    
    // Statements
    return temp;
}   // myFloor

static double myPow (double x, int y) 
{ 
    // Local Declarations
    double temp; 
    
    // Statements
    if (y == 0) 
       return 1; 
    temp = myPow (x, y / 2);        
    if (y % 2 == 0) 
        return temp * temp; 
    else
    { 
        if (y > 0) 
            return x * temp * temp; 
        else
            return (temp * temp) / x; 
    }   // else 
}   // myPow

static double ln (double x)
{
    // Local Declarations
    double frac, newSum, denom = 1.0, origSum = 0.0;
    double exprsn = frac = newSum = (x - 1) / (x + 1);
    double exprsnSq = myPow (exprsn, 2.0);

    // Statements
    while (newSum != origSum)
    {
        origSum = newSum;
        denom += 2.0;
        frac *= exprsnSq;
        newSum += frac / denom;
    }   // while
    return 2.0 * newSum;
}   // ln

static double myLog10 (double x) {
    // Local Declarations
    static double ln10 = 2.3025850929940456840179914546844;
    
    // Statements
    return ln(x) / ln10;    
}   // myLog10

static double smoothCount (double x)
{
    // Local Declarations
    int k = 0;
    double i = myFloor (myLog10 (x) / myLog10 (3)), result = 0;
    
    // Statements
    while (k <= (int) i)
    {
        result = result + myFloor (myLog10 (x / myPow (3, k)) / myLog10 (2));
        k++;
    }   // while
    // Used to debug 3-smooth sequence count
    // printf("%f\n", result + 1 + i);
    return result + 1 + i;
}   // smoothCount

long* Generate_2p3q_Seq (int length, int* seq_size)
{
    // Local Declarations
    double count = smoothCount ((double) length);
    int i = -1, j = 1, nextInd = 0, powOf3 = 3;
    long* sequence = (long*) malloc (sizeof (long) * count);
    if (sequence == NULL)
    {
        *seq_size = 0;
        return NULL;
    }   // if
    
    // Statements
    while (j < length)
    {
        i++;
        sequence[i] = j;
        if (sequence[nextInd] * 2 > powOf3)
        {
            j = powOf3;
            powOf3 *= 3;
        }   // if
        else 
        {
            j = sequence[nextInd] * 2;
            nextInd++;
        }   // else
    }   // while
    *seq_size = (int) (count) - 1;
    /*
    // Checks to make sure seq_size matches i
    if (*seq_size != i)
    {
        printf("Calculated and counted enumerations do not match!\n");
        printf("Calculated %d\n", *seq_size);
        printf("Counted    %d\n", i);
        free(sequence);
        exit(EXIT_FAILURE);
    }
    */
    return sequence;
}   // Generate_2p3q_Seq