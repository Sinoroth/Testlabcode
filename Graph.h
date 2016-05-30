#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include<stdlib.h>
#include "Vector.h"
#include "string.h"


struct node
{
    int nrOfDescriptions;
    struct node *left;
    struct node *right;
    int height;
    int size;
    char* word;
    Vector description;
};

int compare_strings(char* word1,char* word2,int size1,int size2);
int max(int a, int b);

int node_height(struct node *N);

struct node* newNode(Vector Word,Vector description,int nrofDescrp);

struct node *rightRotate(struct node *y);

struct node *leftRotate(struct node *x);

int getBalance(struct node *N);

struct node* updateDescription(struct node* node,char* word,Vector description,int wordSize);

struct node* lookUp(struct node* node,char* word,int wordSize);

struct node* insert(struct node* node, Vector word,Vector description,int nrofDescrp);

#endif
