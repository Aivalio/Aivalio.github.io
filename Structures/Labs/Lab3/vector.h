#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef int datatype;

typedef struct vector_struct {
    datatype* array;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_create(size_t capacity);
void vector_free(Vector* vector);
datatype vector_at(Vector* vector, int index);
void vector_set_at(Vector* vector, int index, datatype data);
void vector_push_back(Vector* vector, datatype data);
size_t vector_size(Vector* vector);
size_t vector_capacity(Vector* vector);

#endif
