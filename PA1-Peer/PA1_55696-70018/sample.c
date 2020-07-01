#include <stdio.h>
#include <stdlib.h>

#include "sample.h"
//struct node *ya;

//function to create a node
struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;
    p->height;

    return p;
}
/*not needed
struct node* search(struct node *root, int x)
{
    if(root==NULL)
        return root;
    else if(x>=root->data)
        return search(root->right_child, x);
    else
        return search(root->left_child,x);
}
*/

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int Bal(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left_child) - height(N->right_child);
}
int max(int a, int b)
{
    return (a > b)? a : b;
}


struct node *rightRotate(struct node *y)
{
    struct node *x = y->left_child;
    struct node *Temp = x->right_child;

    // Perform rotation
    x->right_child = y;
    y->left_child = Temp;

    // Update heights
    y->height = max(height(y->left_child), height(y->right_child))+1;
    x->height = max(height(x->left_child), height(x->right_child))+1;

    // Return new root
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y =malloc(sizeof(struct node));
    struct node *Temp=malloc(sizeof(struct node));
    y = x->right_child;
    Temp = y->left_child;

    // Perform rotation
    y->left_child = x;
    x->right_child = Temp;

    //  Update heights
    x->height = max(height(x->left_child), height(x->right_child))+1;
    y->height = max(height(y->left_child), height(y->right_child))+1;

    // Return new root
    return y;
}

    struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
          root->right_child = insert(root->right_child, x);
    else // x is equal to or smaller should be inserted to left
          root->left_child = insert(root->left_child,x);
    //ya=root;
       /* 2. Update height of this ancestor node */
    root->height = 1 + max(height(root->left_child),
                           height(root->right_child));


    //int balance = Bal(ya);

    // For unbalanced, then there are 4 cases


    // Left Left Case
    if (Bal(root) > 1 && Bal(root->left_child) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (Bal(root) > 1 && Bal(root->left_child) < 0)
    {
        root->left_child =  leftRotate(root->left_child);
        return rightRotate(root);
    }

    // Right Right Case
    if (Bal(root) < -1 && Bal(root->right_child) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (Bal(root) < -1 && Bal(root->right_child) > 0)
    {
        root->right_child = rightRotate(root->right_child);
        return leftRotate(root);
    }

    return root;

}

//function to find the maximum value in a node
struct node* find_maximum(struct node *root)
{

    struct node* temp =  root;
    /* loop down to find the rightmost leaf */
    while (temp->right_child!= NULL)
        temp = temp->right_child;

    return temp;
}

//Delete Node function and balancing
struct node* deleteNode(struct node *root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE


    // For key smaller than root's key, then node lies in left subtree
    if (key < root->data)
        root->left_child = deleteNode(root->left_child, key);

        // For key grater than root's key, then node lies in right subtree
    else if (key > root->data)
        root->right_child = deleteNode(root->right_child, key);

        //verifying if the node is the same as to be deleted
    else {
        // node with only one child or no child
        if ((root->left_child == NULL) || (root->right_child == NULL)) {
            struct node *temp = root->left_child ? root->left_child :
                                root->right_child;

            // when there is no child
            if (temp == NULL) {
                temp = root;
                root = NULL;

            } else // One child case
                *root = *temp; // Copy the contents of
            // the non-empty child
            free(temp);
        } else {
            // when two children are there. getting the inorder predecessor
            struct node *temp = find_maximum(root->left_child); // finding the maximum on the left side of the root

            // Copy the inorder predecessor's data to this node
            root->data = temp->data;

            // Delete the inorder predecessor
            root->left_child = deleteNode(root->left_child, temp->data);
            // ya =root;
        }
        // ya/root variable is currently holding the latest worked root/ya
        // If the tree had only one node then return
        if (root == NULL)
            return root;

        // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
        root->height = 1 + max(height(root->left_child),
                               height(root->right_child));

        //        int balance = Bal(root);

        // For unbalanced node, then there are 4 cases

        // Left Left Case
        if (Bal(root) > 1 && Bal(root->left_child) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (Bal(root) > 1 && Bal(root->left_child) < 0) {
            root->left_child = leftRotate(root->left_child);
            return rightRotate(root);
        }

        // Right Right Case
        if (Bal(root) < -1 && Bal(root->right_child) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (Bal(root) < -1 && Bal(root->right_child) > 0) {
            root->right_child = rightRotate(root->right_child);
            return leftRotate(root);
        }

        return root;
    }
}


void Postorder(struct node* root)
{
    if (root==null) //to terminate the infinite recursion
        return;
    // first left subtree
    Postorder(root->left_child);

    // right subtree
    Postorder(root->right_child);

    // printing the node
    printf("%d ", root->data);
    return;
}

int evaluate (struct *node, FILE * file_ptr)
{

}
