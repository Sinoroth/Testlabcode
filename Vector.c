#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

void vector_init(Vector *vector) {
  // initialize size and capacity
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;

  // allocate memory for vector->data
  vector->data = malloc(sizeof(char) * vector->capacity);
}

void vector_append(Vector *vector, char value) {
  // make sure there's room to expand into
  vector_double_capacity_if_full(vector);

  // append the value and increment vector->size
  vector->data[vector->size++] = value;
}

char vector_get(Vector *vector, int index) {
  if (index >= vector->size || index < 0) {
    printf("Index %d out of bounds for vector of size %d\n", index, vector->size);
    exit(1);
  }
  return vector->data[index];
}

int vector_size(Vector *vector)
{
    return vector->size;
}

void vector_remove_lastelement(Vector *vector)
{
    vector->data[vector->size--]=NULL;
}
/*
void vector_set(Vector *vector, int index, char value) {
  // zero fill the vector up to the desired index
  while (index >= vector->size) {
    vector_append(vector, 0);
  }

  // set the value at the desired index
  vector->data[index] = value;
}
*/
void vector_double_capacity_if_full(Vector *vector) {
  if (vector->size >= vector->capacity) {
    // double vector->capacity and resize the allocated memory accordingly
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(char) * vector->capacity);
  }
}

void vector_free(Vector *vector) {
  //free(vector->data);
  int i;
  for(i=vector->size-1;i>=0;--i)
    {
    vector->data[i]=NULL;
    }
  vector->size = 0;
}
