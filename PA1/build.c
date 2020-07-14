#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "build.h"
#include "move.h"


int max(int x, int y)
{
	return ((x > y)? x: y);
}

//make sure rc and lc are always passed as 0
int height(TreeNode * head)
{
	
	//int temp;
	
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return(head->height);
	}
}

int bal(TreeNode * head)
{
	if(head == NULL)
	{
		return 0;
	}
	return (height(head->left) - height(head->right));
}

TreeNode * createnode(int num)
{
	TreeNode * head = malloc(sizeof(struct TNode));
	if(head == NULL)
	{
		fprintf(stderr, "\nmemory allocation issue\n");
		fprintf(stdout, "%d\n", 0);
	}
	head -> key = num;
	head -> left = NULL;
	head -> right = NULL;
	head -> height = 0;
	return head; //might need to add an ampersand
}

TreeNode * insert(TreeNode * head, int key)
{
	//Variable Declarations
	int equiv;

	//If less than or equal too throw it on the left if the pointer isnt Null move to left child
	if(head == NULL)
	{
		return(createnode(key));
	}
	if(key <= head-> key)
	{
		head -> left = insert(head -> left, key);
	}	
	else if(key > head->key)
	{
		head -> right = insert(head -> right, key);
	}
	
	//update height after every addition
	head->height = 1 + max(height(head->left),height(head->right)); //height should return the height, if its null it should be 0
	
	//check the balance for rotations
	equiv = bal(head);
	

	if(equiv > 1 && key <= head->left->key)
	{
		return rightRotate(head);
	}
	

	if(equiv < -1 && key > head->right->key)
	{
		return leftRotate(head);
	}
	//Left Right
	if(equiv > 1 && key > head->left->key)
	{
		head->right=leftRotate(head->left);
		return (rightRotate(head));
	}
	//Right Left
	if(equiv < -1 && key <= head -> right -> key)
	{
		head->right = rightRotate(head->right);
		return (leftRotate(head));
	}

	return head;	

}



