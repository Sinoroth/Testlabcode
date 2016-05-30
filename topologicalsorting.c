#include "topologicalsorting.h"

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
