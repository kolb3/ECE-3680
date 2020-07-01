//
// Created by anubh on 6/29/2020.
//

#ifndef UNTITLED_SAMPLE_H
#define UNTITLED_SAMPLE_H

#include <stdlib.h>
#include <stdio.h>


typedef  struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
    int height;
};

struct node* new_node(int x);
int height(struct node *N);
int Bal(struct node *N);
int max(int a, int b);
struct node *rightRotate(struct node *y);
struct node *leftRotate(struct node *x);
struct node* insert(struct node *root, int x);
struct node* find_maximum(struct node *root);
struct node* deleteNode(struct node *root, int key);




#endif //UNTITLED_SAMPLE_H
