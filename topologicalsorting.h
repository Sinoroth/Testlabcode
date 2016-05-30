#ifndef TOPOLOGICALSORTING_H
#define TOPOLOGICALSORTING_H


struct node
{
    int n;
    node* next;
}*G[MAX];

typedef struct color
{
   int val;
}color[100];

typedef struct List
{
    int* lst;
    int numberofElements;
    int capacity;
}List;

void DF_TOP(int nod,List* list);

void list_init(List* list);

void add(int x,int y);

void push_back(List* list, int val);

#endif // TOPOLOGICALSORTING_H
