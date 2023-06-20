#include "../Include/ArrayStack.h"
#include <stdlib.h>

/**
 * Initialization
 */
ArrayStack* stack_init() {
    // Allocate space
    ArrayStack* stack_pointer = (ArrayStack*) malloc(sizeof(ArrayStack));
    
    // Initialize struct
    stack_pointer->capacity = 10;
    stack_pointer->array = (void**) malloc(sizeof(void*) * stack_pointer->capacity);
    stack_pointer->top = -1;
    return stack_pointer;
}

/**
 * Push an element to the top of the stack
 */
void stack_push(ArrayStack* stack_pointer, void* data) {
    // Extend the space when the stack is full
    if (stack_pointer->top == stack_pointer->capacity - 1) {
        stack_pointer->capacity *= 2;
        stack_pointer->array = (void**) realloc(stack_pointer->array, sizeof(void*) * stack_pointer->capacity);
    }
    // Push the data to the top of the stack
    stack_pointer->array[++stack_pointer->top] = data;
}

/**
 * Remove the element at the top of the stack
 */
void* stack_pop(ArrayStack* stack_pointer) {
    // Return the top item, and remove it
    return stack_pointer->array[stack_pointer->top--];
}

/**
 * Check if the stack is empty
 */
short stack_is_empty(const ArrayStack* stack_pointer) {
    return (short) (stack_pointer->top == -1);
}

/**
 * Get the number of elements within the stack
 */
int stack_get_length(const ArrayStack* stack_pointer) {
    return stack_pointer->top + 1;
}

/**
 * Peek the element at the top of the stack
 */
void* stack_peek(const ArrayStack* stack_pointer) {
    return stack_pointer->array[stack_pointer->top];
}

/**
 * Check if an element is within the stack
 */
short stack_contain(const ArrayStack* stack_pointer, const void* item, int (*comp)(const void*, const void*)) {
    for (int i = 0; i <= stack_pointer->top; i++) {
        if (comp(stack_pointer->array[i], item) != 0) {
            return 1;
        }
    }
    return 0;
}

/**
 * Remove every element within the stack
 */
void stack_clear(ArrayStack* stack_pointer) {
    for (int i = 0; i < stack_get_length(stack_pointer); i++) {
        free(stack_pointer->array[i]);
    }
    stack_pointer->top = -1;
}

/**
 * Destroy the stack
 */
void stack_destroy(ArrayStack* stack_pointer) {
    stack_clear(stack_pointer);
    free(stack_pointer->array);
    free(stack_pointer);
}