#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "build.h"


//Preorder
void Preorder(ListNode * head)
{

}

ListNode* CreateNode(int n, int dim, int* arr)
{
	// Same as previous HW
	ListNode * head = malloc(sizeof(ListNode));
	if(head == NULL)
	{
		fprintf(stderr, "memallocation of head didnt work\n");
	}
	head -> next = NULL;
	// initialize dim
	TreeNode * new = malloc(sizeof(TreeNode)); // Possibly need to create a second head
	if(new == NULL)
	{
		fprintf(stderr, "mem alloc of treenode didnt work\n");
	}
	head -> treenode = new;
	new -> dimension = dim;
	// both left and right childern will be NULL
	new -> left = NULL;
	new -> right = NULL;
	// allocate memory for data
	new -> data = malloc(sizeof(int) * dim);
	for(int i = 0; i < dim; i++)
	{
		new -> data[i] = arr[i];
	}
	// return a ListNode
	return head;
}

void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// Same as previous HW
	ListNode * one = NULL;
 	ListNode * two = NULL;
 	int spot = 0;

	int * arr = malloc(sizeof(int) * n * dim);
 	for(int q = 0; q < (n * dim); q++)
 	{
		 fscanf(fptr, "%d", &arr[q]);
 	}
 	for(int i = 0; i < n; i++)
 	{
	spot = i;
	 	if(i == 0)
	 	{
			 *head = CreateNode(n, dim, arr);
		 	one = *head;
	 	}
	 	else
	 	{
			two = CreateNode(n,dim,&arr[(spot*dim)]);
		 	one -> next = two;
		 	one = two;
	 	}

 	}
	free(arr);
}


