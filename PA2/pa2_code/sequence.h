#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

long *Generate_2p3q_Seq(int length, int *seq_size);
void sort(long * key, int count);
int exponent(int a, int b); //added this for the power function
int quot(int a, int b); //added this to find the exponent number needed
int noexist(long comp, int size, long * arr);

#endif
