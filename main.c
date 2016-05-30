#include <stdio.h>
#include <stdlib.h>
typedef struct Nod {
    int data;                                   //ce va retine fiecare nod
    struct Nod * next;                          //pointeri catre elementul urmator
}Nod;

Nod *G[101];
int color[101];

typedef struct List
{
    int *lst;
    int capacity;
    int size;
}List;

List lest;

void push_back(List* list, int val)
{
     if(list->size >= list->capacity)list->capacity*=2;
     list->lst = realloc(list->lst, sizeof(int) * list->capacity);

     list->lst[list->size++]=val;

}

int list_size(List* list)
{
    return list->size;

}

int list_elem(List* list,int poz)
{
    return list->lst[poz];

}

void list_init(List* list)
{
   list->size = 0;
   list->capacity = 1000;

   list->lst =  malloc(sizeof(int) * list->capacity);
}

void DF_TOP(int nod)
{
   Nod *q = G[nod];
   color[nod] = 1;

   for(;q!=NULL;q=q->next)
    {
      if(!color[q->data])DF_TOP(q->data);
    }

    push_back(&lest,nod);

}

void add(int x,int y)
{
    Nod* q = (Nod*) malloc(sizeof(Nod));
    q->data = y;
    q->next=G[x];
    G[x]=q;
}

int main()
{
    int N,M,i,x,y;
    for(i=0;i<101;++i)color[i]=0;
    list_init(&lest);
    FILE* file = fopen ("sortaret.in", "r");
    FILE* f = fopen ("sortaret.out", "w");



    fscanf (file, "%d", &N);
    fscanf (file, "%d", &M);
    for(i=1;i<=M;++i)
        {
        fscanf (file, "%d", &x);
        fscanf (file, "%d", &y);
        add(x,y);
        }

    for(i=1;i<=N;++i)
        if(!color[i])
        DF_TOP(i);

    for(i=list_size(&lest)-1;i>=0;--i)
          //fscanf(f,"%d",list_elem(&lest,i));
          printf("%d ",list_elem(&lest,i));
    return 0;
}
