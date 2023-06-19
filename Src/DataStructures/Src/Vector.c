#include <stdlib.h>
#include "../Include/Vector.h"

Vector* vector_init(int length, void (*free_function)(void *), int (*compare_function)(const void *, const void *)) {
    Vector* vector_ptr = (Vector*) malloc(sizeof(Vector));
    vector_ptr->array = (void**) malloc(sizeof(void *) * length);
    vector_ptr->length = length > 0 ? length : 1;
    vector_ptr->count = 0;
    vector_ptr->free_function = free_function;
    vector_ptr->compare_function = compare_function;
    return vector_ptr;
}

void vector_append(Vector *vector_ptr, void *item) {
    if (vector_ptr->count == vector_ptr->length) {
        vector_ptr->length *= 2;
        vector_ptr->array = (void**) realloc(vector_ptr->array, sizeof(void*) * vector_ptr->length);
    }
    vector_ptr->array[vector_ptr->count++] = item;
}


