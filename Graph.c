#include "Graph.h"
#include "string.h"

int compare_strings(char *word1,char *word2,int size1, int size2)
{
     int str=0,i;

      for(i=0;i<size2;++i)
                    {
                    if(word2[i]>word1[i])
                        {
                        str = 1;
                        break;
                        }
                    if(word2[i]<word1[i])
                        {
                        str = -1;
                        break;
                        }
                    }
                if(size2<size1 && str==0)str = -1;
                if(size2>size1 && str==0)str = 1;

     return str;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

int node_height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

struct node* newNode(Vector Word,Vector description,int nrofDescrp)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->word = malloc(sizeof(char) * vector_size(&Word));
    node->nrOfDescriptions = nrofDescrp;
    node->left  = NULL;
    node->right = NULL;
    node->height = 1;
    node->size = vector_size(&Word);
    vector_init(&node->description);

    int i,size;
    size = vector_size(&description);

    for(i=0;i<size;++i)
        {
        vector_append(&node->description,vector_get(&description,i));
        }

    size = vector_size(&Word);
    for(i=0;i<size;++i)
        {
        node->word[i]= vector_get(&Word,i);
        }
    return(node);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;


    x->right = y;
    y->left = T2;


    y->height = max(node_height(y->left), node_height(y->right))+1;
    x->height = max(node_height(x->left), node_height(x->right))+1;


    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;


    y->left = x;
    x->right = T2;


    x->height = max(node_height(x->left), node_height(x->right))+1;
    y->height = max(node_height(y->left), node_height(y->right))+1;


    return y;
}


int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return node_height(N->left) - node_height(N->right);
}

struct node* lookUp(struct node* node,char* word,int wordSize)
{
        int str;
        if(node!=NULL)
            {
               /* str = 0;
                int i,size;
                size = node->size;


                for(i=0;i<wordSize;++i)
                    {
                    if(word[i]>node->word[i])
                        {
                        str = 1;
                        break;
                        }
                    if(word[i]<node->word[i])
                        {
                        str = -1;
                        break;
                        }
                    }
                if(wordSize<size && !str)str = 1;
                if(wordSize>size && !str)str = -1;
*/
            str = compare_strings(node->word,word,node->size,wordSize);
            if(str<0){lookUp(node->left,word,wordSize);}
            else if(str>0){lookUp(node->right,word,wordSize);}
            else if(str == 0)
                {
                     int i,size;

                     size = vector_size(&node->description);

                     for(i=0;i<size;++i)
                        {
                        if(isdigit(vector_get(&node->description,i)))
                            {
                            printf("\n");
                            }
                        printf("%c",vector_get(&node->description,i));
                        }
                    printf("\n\n");
                }
            }
        else
            {
            printf("The word you are looking for doesn't exist.");
            }

}

struct node* updateDescription(struct node* node,char* word,Vector description,int wordSize)
{
        int str;
        if(node!=NULL)
            {

             str = compare_strings(node->word,word,node->size,wordSize);
            if(str<0){updateDescription(node->left,word,description,wordSize);}
            else if(str>0){updateDescription(node->right,word,description,wordSize);}
            else
                {
                     ++node->nrOfDescriptions;
                     printf("%d",node->nrOfDescriptions);
                     vector_append(&node->description,' ');
                     vector_append(&node->description,node->nrOfDescriptions + '0');
                     vector_append(&node->description,'.');
                     vector_append(&node->description,' ');

                     int i=0,size = vector_size(&description);

                     for(;i<size;++i)
                        {
                        vector_append(&node->description,vector_get(&description,i));
                        }
                    vector_remove_lastelement(&node);
                    vector_append(&node->description,'.');
                }
            }
        else
            {
            printf("The word you are looking to update doesn't exist.");
            }

}



struct node* insert(struct node* node, Vector word,Vector description,int nrofDescrp)
{

    if(node == NULL){return(newNode(word,description,nrofDescrp));}

    int comp,compLeft,compRight;
    char* currentWord = malloc(sizeof(char) * vector_size(&word));

     int i,size,str=0;

    size = vector_size(&word);

    for(i=0;i<size;++i)
        {
          currentWord[i] = vector_get(&word,i);
        }

     str = compare_strings(node->word,currentWord,node->size,size);
      if (str < 0)
        {
        node->left  = insert(node->left, word,description,nrofDescrp);
        }
    else
        {
        node->right = insert(node->right, word,description,nrofDescrp);
        }

    node->height = max(node_height(node->left), node_height(node->right)) + 1;


    int balance = getBalance(node);

    if(node->left !=NULL )
        {
            //str = strcmp(currentWord,node->left->word);
             str = compare_strings(node->left->word,currentWord,node->left->size,size);
         if (balance > 1 && str<0 ){return rightRotate(node);}
        }

    if(node->right !=NULL )
        {
          //  str = strcmp(currentWord,node->right->word);
             str = compare_strings(node->right->word,currentWord,node->right->size,size);
             if (balance < -1 && str>0 )
            {
                  return leftRotate(node);
            }
        }

   if(node->left !=NULL )
        {
           //str = strcmp(currentWord,node->left->word);
           str = compare_strings(node->left->word,currentWord,node->left->size,size);
           if (balance > 1 && str>0 )
            {
                node->left =  leftRotate(node->left);
                return rightRotate(node);
            }
        }


    if(node->right !=NULL )
        {
            //str = strcmp(currentWord,node->right->word);
            str = compare_strings(node->right->word,currentWord,node->right->size,size);
           if (balance < -1 && str<0 )
            {
                  node->right = rightRotate(node->right);
                  return leftRotate(node);
            }
        }

    return node;
}
