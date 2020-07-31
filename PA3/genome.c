#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "genome.h"


//Peer Review
//Sorry the code is a bit sloppy atm, however I did go for the easier approach I have not Tested it to the fullest extent but it does compile. My thought process to walk you through to make it easier to under stand is create head then read the input, using the total number of possibilites create an array that for each potential hash moves from a 0, to a 1 if that string has been used. Else save in a new node, then output the total number of different strings possible.

//with the normal problem where we have to create the graph I am really not sure what the edges are supposed to be used for, or how they will relate. The other thing is I use next in GNode it didnt have it previously I dont think you can get around not having next at least to me it doesnt make sense. So my question would be is it possible to explain the edges better? Or give a better example on how to use them, I think I can modify this slightly and get it to output what I need for the test anyway which wouldnt be too bad.

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

  GNode * newhead = NULL;

  //should i create the node here? also do i need
  //create a create .c where you create the listhead and gnode  
  //LinkedListCreate(newhead);


  inputread(k_len, inputFilename, &newhead); //reads the inputs from the file
  writeoutput(outputFilename, newhead, k_len);
 
  GNode * temp = NULL;

  while(newhead -> next != NULL)
  {
	temp = newhead -> next -> next;
	free(newhead->next->key); 
	free(newhead->next);
	newhead->next = temp;
  }
  
  free(newhead->key);
  free(newhead);
  
  
  return 0;
}

void inputread(int len, char * file, GNode ** head)
{
	char * in = NULL;
	long size = 0;
	int * arr = NULL;
	long value = 0;
	GNode * hold = NULL; //for holding place
	GNode * store = NULL; //for holding stored value

	//array for hash value check
	size = exponent(size);
	arr = malloc(sizeof(int) * size);
	
	//array for input string
	in = malloc(sizeof(char) * len);
	FILE * fptr = fopen(file, "r");

	while( fread(&in, sizeof(char),len,fptr) == 1)
	{
		fseek(fptr, len - 1, SEEK_CUR);
		value = hash(in,len,size);
	
		if(arr[value] == 0)
		{
			if(head == NULL)	
			{
				(*head) = malloc(sizeof(GNode)); //create intial node
				//head -> prev = NULL;          //since first node previous is null	//dont think i need prev
				(*head) -> next = NULL;          //only allocate memory as needed
				arr[value] = 1;               //change the value for the arr at the hash spot to 1 if its 1 then its not stored
				store = (*head);                 //use store to move through
				InitGNode(store, in, len);    //put all the values into the node
		
			}
			else
			{
				hold = malloc(sizeof(GNode)); //create next node
				//hold -> prev = store;     //set the trace back to the current spot	//dont think i need prev		
				store -> next = hold;         //set the next of the current to the one just created
				hold -> next = NULL;          //next of the one created to null
				arr[value] = 1;               //mark that this is the first instance of this input
				InitGNode(store, in, len);    //store the value into the node
			}
		
		}
	}
	free(in);
	free(arr);
	fclose(fptr);

}

long exponent(int len)  //is a function to measure the total number of possibilities 4^len
{
	long size = 1; //if size 0 then only 1 can be the answer;
	for(int i = 0; i < size; i++)
	{
		size *= 4;
	}
	return size;
}

void writeoutput(char * filename, GNode * head, int len)
{
	GNode * current = NULL;
	//GNode * temp = NULL;
	current = head;

	FILE * fptr = fopen(filename, "w");			     //open file

	while(current != NULL)
	{
		fwrite(current->key, sizeof(char),len,fptr);   //write the value from the node
		fwrite("\n", sizeof("\n"),1,fptr);
		current = current -> next;  			     //cycle through nodes to print
	}
	fclose(fptr);

}


 
