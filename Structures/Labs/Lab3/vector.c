#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

struct vector_struct {
    datatype*   array;
    size_t      size;
    size_t      capacity;
};


// Free all memory allocated for the vector.
void vector_free(Vector* vector) {
    
    if(vector) {

        free(vector->array);
        free(vector);
    }
}

// Return the value stored at the given index.
datatype vector_at(Vector* vector, int index) {

    if(index>=0 && index<vector->size) {
        return vector->array[index];
    }
    
    else return 0;
}

// Set the value stored at the given index.
void vector_set_at(Vector* vector, int index, datatype data) {
   
    if(index>=0 && index<vector->size) {
        vector->array[index]=data;
    } 
}

// Add a new value at the end of the vector, resizing if necessary.
void vector_push_back(Vector* vector, datatype data) {

    if(vector->capacity==vector->size) {

        vector->capacity = (vector->capacity == 0) ? 1 : vector->capacity * 2;
        vector->array=realloc(vector->array, sizeof(datatype)*vector->capacity);

        if(vector->array==NULL) {
            fprintf(stderr, "Failed to allocate memory\n");
            exit(EXIT_FAILURE);
        }
        
    }
    vector->array[vector->size++]=data;
}

// Return the number of elements in the vector.
size_t vector_size(Vector* vector) {
    
    return vector->size;
}

// Return the total capacity of the vector.
size_t vector_capacity(Vector* vector) {
   
    return vector->capacity;
}

Vector*vector_create(size_t capacity) {

    Vector*v=malloc(sizeof(Vector));
    if(v==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    v->array=malloc(sizeof(datatype)*capacity);
    if(v->array==NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        free(v);
        exit(EXIT_FAILURE);
    }

    v->capacity=capacity;
    v->size=0;

    return v;
}


