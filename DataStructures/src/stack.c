#include "../include/stack_adt.h"
#include <stdlib.h>

Stack* stack_init(void (*free_function)(void *)) {
    // Allocate space
    Stack* stack_pointer = (Stack*) malloc(sizeof(Stack));
    
    // Initialize struct
    stack_pointer->free_function = free_function;
    stack_pointer->allocated = 10;
    stack_pointer->memory = (void**) malloc(sizeof(void*) * stack_pointer->allocated);
    stack_pointer->top = -1;
    return stack_pointer;
}

void stack_push(Stack* stack_pointer, void* data) {
    // Extend the space when the stack is full
    if (stack_pointer->top == stack_pointer->allocated - 1) {
        stack_pointer->allocated *= 2;
        stack_pointer->memory = (void**) realloc(stack_pointer->memory, sizeof(void*) * stack_pointer->allocated);
    }
    // Push the data to the top of the stack
    stack_pointer->memory[++stack_pointer->top] = data;
}

void* stack_pop(Stack* stack_pointer) {
    // Return the top item, and remove it
    return stack_pointer->memory[stack_pointer->top--];
}

short stack_is_empty(Stack* stack_pointer) {
    return (short) (stack_pointer->top == -1);
}

int stack_get_length(Stack* stack_pointer) {
    return stack_pointer->top + 1;
}

void* stack_peek(Stack* stack_pointer) {
    return stack_pointer->memory[stack_pointer->top];
}

short stack_contain(Stack* stack_pointer, void* item, int (*comp)(const void*, const void*)) {
    for (int i = 0; i <= stack_pointer->top; i++) {
        if (comp(stack_pointer->memory[i], item) == 0) {
            return 1;
        }
    }
    return 0;
}

void stack_clear(Stack* stack_pointer) {
    for (int i = 0; i < stack_get_length(stack_pointer); i++) {
        stack_pointer->free_function(stack_pointer->memory[i]);
    }
    stack_pointer->top = -1;
}

void stack_destroy(Stack* stack_pointer) {
    stack_clear(stack_pointer);
    free(((Stack* ) stack_pointer)->memory);
    free(stack_pointer);
}