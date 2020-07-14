#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "build.h"
#include "move.h"

void Preorder(TreeNode * head)
{

	if(head == NULL);
	{
		return;
	}
	printf("%d\n", head->key);
	Preorder(head->left);
	Preorder(head->right);

}

void freenode(TreeNode * head)
{
	TreeNode * temp = head;
	if(temp == NULL)
	{
		return;
	}
	freenode(temp->left);
	freenode(temp->right);	
	if((temp->left == NULL) && (temp->right == NULL))
	{
		free(temp);
		return ;
	}
}

int main(int argc, char * * argv)
{
	//variable declarations
	int key;
	char action;
	char hold;
	int ct;
	int i;
	//char * instruct;


	// check for input error
	if(argc < 2)
	{
		fprintf(stderr, "need 3 inputs, instruct, input, and output\n");
		return EXIT_FAILURE;
	}
	//printf("%s\n",argv[1]);
	//printf("%s\n",argv[0]);

	// open the file
	FILE * fptr = fopen(argv[2], "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen did not work\n");
    		fprintf(stdout, "%d\n", -1);
		return EXIT_FAILURE;
	}
	//key = malloc(sizeof(int) + sizeof(char));
	TreeNode * newhead = NULL;
	fseek(fptr,0, SEEK_END);
	ct = ftell(fptr);
	//printf("\n\n\nTHIS IS CT: %d\n\n\n",ct);
	fseek(fptr,0,SEEK_SET);
	ct = ct / 5;

	for(i = 0; i <= ct; i++)//fread(&key, sizeof(int) + sizeof(char),1, fptr) == 1
	{
		//key = fread(&val, sizeof(int),fptr);
		fscanf(fptr, "%d", &key);
		fscanf(fptr, "%c", &hold);
		fscanf(fptr, "%c", &action);
		//fread(&key, sizeof(int),1, fptr);
		//fread(&action, sizeof(char),1, fptr);

		
		printf("\n%d ..%c..",key,action);
		//printf("\n%c",stop);
		if(action == 'i')
		{
			printf("\nhello");
			newhead = insert(newhead,key);
		}
		else if(action == 'd')
		{
			printf("\ngoodbye");
			//newhead = deleteNode(newhead,key);
		}
		/*if()
		{
			stop = 0;
			printf("\nstop: %d\n",stop);
		}*/
		//printf("\ni:%d ct:%d ",i,ct);
	}//while(stop);
	fclose(fptr);

  	//instruct = argv[0];

  	if(strcmp(argv[1],"-b"))
  	{
	    	//build height balanced BST
  	}
  	else if(strcmp(argv[1], "-e"))
  	{
    		//evaluate height balanced BST
		printf("\nYOU MADE IT!!!\n");
  	}
  	else
  	{
      		fprintf(stderr, "intructions need to be either -b or -e!\n");
      		return EXIT_FAILURE;
  	}
	//printf("\n%d\n",newhead->key);
	Preorder(newhead);

	freenode(newhead);


  	fprintf(stdout, "%d\n", 0);
	printf("\nMADE IT TO THE END!\n");
  	EXIT_SUCCESS;
}
