#include "file.h"
#include "vector.h"

Vector FilesRead(char *fileName)
{
    FILE *fl;
    Vector fileText;
    vector_init(&fileText);
    int i;
    char txt[200];

    fl = fopen(fileName,"r");

    while(fgets(txt,200,fl)!=NULL)
        {
            i=0;
            for(;txt[i]!=NULL;++i)
                {
                  vector_append(&fileText,txt[i]);
                }
        }
    return fileText;
}

void FilesWrite(char *fileName,Vector *fileText)
{
    char* text;
    FILE *fl;
    int i,size;

    //text = vector_text(fileText);

    size = vector_size(fileText);

    for(i=0;i<size;++i)
        {
        text[i]=vector_get(fileText,i);
        }

    text[size-1]=NULL;

    fl = fopen(fileName,"w");


    fprintf(fl,"%s",text);

}
