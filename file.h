#ifndef FILE_H
#define FILE_H
#include<stdio.h>
#include "vector.h"

Vector FilesRead(char *fileName);

void FilesWrite(char *fileName,Vector *fileText);

#endif // FILE_H
