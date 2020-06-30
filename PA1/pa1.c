#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "build.h"


int main(int argc, char * * argv)
{
	// check for input error
	if(argc < 2)
	{
		fprintf(stderr, "need 3 inputs, instruct, input, and output\n");
		return EXIT_FAILURE;
	}

	// open the file
	FILE * fptr = fopen(argv[1], "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen did not work\n");
    fprintf(stdout, "%d\n", -1);
		return EXIT_FAILURE;
	}

  char instruct;
  instruct = argv[0];

  if(isntruct = "-b")
  {
    //build height balanced BST
  }
  else if(instruct = "-e")
  {
    //evaluate height balanced BST
  }
  else
  {
      fprintf(stderr, "intructions need to be either -b or -e!\n");
      return EXIT_FAILURE;
  }

  /*ListNode * newhead = NULL;
	// Create linkedList
	LinkedListCreate(&newhead, n, dim, fptr);
	// call MakeCluster
	MakeCluster(&newhead);

	fclose(fptr);
	ListNode * temp = newhead->next;

	while(newhead->next != NULL)
	{
		temp = newhead->next->next;
		free(newhead->next->treenode->data);
		free(newhead->next->treenode->left);
		free(newhead->next->treenode->right);
		free(newhead->next->treenode);
		free(newhead->next);
		newhead->next = temp;
	}
	free(newhead->treenode->data);
	free(newhead->treenode->left);
	free(newhead->treenode->right);
	free(newhead->treenode);
	free(newhead);*/

  fprintf(stdout, "%d\n", 0);
  EXIT_SUCCESS;
}
