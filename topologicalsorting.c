#include "topologicalsorting.h"

typedef struct Nod {
    int data;                                   //ce va retine fiecare nod
    struct Nod * next;                          //pointeri catre elementul urmator
}Nod;

Nod *G[100];
int color[100];


void DF_TOP(int nod)
{
   Nod *q = G[nod];
   color[nod] = 1;

   for(;q!=NULL;q=q->next)
    {
      if(!color[q->data])DF_TOP(q->data);

    }

}


void add(int x,int y)
{
    Nod* q = (Nod*) malloc(sizeof(Nod));
    q->data = y;
    q->next=G[x];
    G[x]=q;
}

void DF_TOP(int nod)
{
   node*q = G[nod];
   color[nod] = 1;
   for(;q!=NULL;q=q->next)
    {
      if(!color[q->n])DF_TOP(q->n);

    }
    lst.push_back(nod);
}

void push_back(List* list, int val)
{
     if(list->size >= list->capacity)list->capacity*=2;
     list->data = realloc(list->data, sizeof(int) * list->capacity);

     list->lst[lst->size++]=val;

}

void list_init(List* list)
{
   list->numberofElements = 0;
   list->capacity = 0;

   list->lst =  malloc(sizeof(int) * list->capacity);
}

void add(int x,int y)
{
    node* q = new node;
    q->n = y;
    q->next=G[x];
    G[x]=q;
}
