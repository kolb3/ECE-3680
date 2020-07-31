#ifndef __GENOME_H_
#define __GENOME_H_

#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_KMER_LEN 16

int getval(char c){
  switch (c){
    case 'A': case 'a':
      return 0;
    case 'C': case 'c':
      return 1;
    case 'G': case 'g':
      return 2;
    case 'T': case 't':
      return 3;
    default:
      return 0;
  }
  return 0;
}

typedef struct GNode{
  char key[MAX_KMER_LEN];/// Will hold strings only consisting of ACGT
  int inEdges[4]; ///Edges can be A,C,G,or T. 0 = A, 1 = C, 2 = G, 3 = T
  int outEdges[4]; ///Edges can be A,C,G,or T. 0 = A, 1 = C, 2 = G, 3 = T
  int key_len;/// this is our k length
  //struct GNode * prev;
  struct GNode * next;
}GNode;


void InitGNode(GNode* node, char* k, int kl){
  int max_chars = kl < MAX_KMER_LEN ? kl : MAX_KMER_LEN;
  if(max_chars != kl){
    printf("Can't save the length of the key correctly. Exiting program.\n");
    exit(1);
  }
  strncpy(node->key, k, kl);
  node->key[kl] = '\0';
  node->key_len = kl;
}

long hash(char * key, int len, long GRAPH_SIZE){///this can be used to determine if string exists already //make sure to alter with out node add array of chars
  long toRet = 0;
  int i;
  for(i = 0; i < len; ++i){
    toRet = toRet << 2;
    toRet |= getval(key[i]);
  }
  toRet = toRet % GRAPH_SIZE;
  return toRet;
}

void inputread(int len, char * file, GNode ** head);
long exponent(int len);
void writeoutput(char * filename, GNode * head, int len);



#endif //__GENOME_H_
