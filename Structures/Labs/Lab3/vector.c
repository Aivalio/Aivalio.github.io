#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

// Free all memory allocated for the vector.
void vector_free(Vector* vector) {
    if (vector) {
        free(vector->array);
        free(vector);
    }
}

// Return the value stored at the given index.
datatype vector_at(Vector* vector, int index) {
    if (index >= 0 && index < vector->size) {
        return vector->array[index];
    }
    fprintf(stderr, "Index out of bounds\n");
    exit(EXIT_FAILURE);
}

// Set the value stored at the given index.
void vector_set_at(Vector* vector, int index, datatype data) {
    if (index >= 0 && index < vector->size) {
        vector->array[index] = data;
    }
}

// Add a new value at the end of the vector, resizing if necessary.
void vector_push_back(Vector* vector, datatype data) {
    if (vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->array = realloc(vector->array, vector->capacity * sizeof(datatype));
        if (!vector->array) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    vector->array[vector->size++] = data;
}

// Return the number of elements in the vector.
size_t vector_size(Vector* vector) {
    return vector->size;
}

// Return the total capacity of the vector.
size_t vector_capacity(Vector* vector) {
    return vector->capacity;
}
