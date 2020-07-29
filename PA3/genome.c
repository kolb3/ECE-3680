

#include <stdio.h>
#include <stdlib.h>

#include "genome.h"

int main(int argc, char* argv[]){
  // argv[1] should be an integer of what our k length should be.
  // argv[2] will be the input filename that will contain the different reads. Each line in the
  // input file corresponds to one read.
  // argv[3] will be the filename of where you should output the strings from your traversal
  if(argc != 4){
    printf("Usage: ./pa4 <k_len> <inputFilename> <outputFilename>\n");
    exit(1);
  }
  int k_len = atoi(argv[1]);
  char* inputFilename = argv[2];
  char* outputFilename = argv[3];

  /*Do some more coding here*/

  LNode * newhead = NULL;

  //should i create the node here? also do i need
  //create a create .c where you create the listhead and gnode  
  //LinkedListCreate(newhead);


  inputread(k_len, inputFilename, newhead); //reads the inputs from the file
  
  return 0;
}

void inputread(int len, char * file, LNode * head)
{
	char * in = NULL;
	in = malloc(sizeof(char) * len);
	FILE * fptr = fopen(file, r);

	fread(&in, sizeof(char) * len,1,fptr);
	//function for exist?	
	//take the head node and create everything then move from there
}

//sorry this is all the farther i have made it, im in the midst of moving, hopefully makes your time a little easier I do have a couple questions though for the GNode the edges how does that work, I am using a Listnode that points to the next node the issue is i wont be able to send multiple connects the read and everything else seems to be something decent to setup im just not sure what to do about that. Also would it make more sense to read in the entire line and then seperate it out or seperate it as it comes in and just seek back, I was planning to read length amount in and then seek back length - 1 and continue until new line. 
