#include "../include/stack_tests.h"
#include "../../DataStructures/include/stack_adt.h"
#include "../UnityUnitTests/src/unity.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/**
 * Generate int pointer from an int value
*/
int* generate_int_pointer(int integer){
    int *newInt = (int *)malloc(sizeof(int));
    *newInt = integer;
    return newInt;
}

/**
 * Generate a stack for testing
*/
Stack* generate_stack() {
    Stack* stack_ptr = stack_init(free);
    stack_push(stack_ptr, generate_int_pointer(10));
    stack_push(stack_ptr, generate_int_pointer(20));
    stack_push(stack_ptr, generate_int_pointer(30));
    stack_push(stack_ptr, generate_int_pointer(40));
    stack_push(stack_ptr, generate_int_pointer(50));
    stack_push(stack_ptr, generate_int_pointer(60));
    return stack_ptr;
}

/**
 * General stack tests
*/
void stack_unit_tests() {
    Stack* stack_ptr = generate_stack();
    int length = stack_get_length(stack_ptr);
    for (int i = 0; i < length; i++){
        int value = *((int *)stack_pop(stack_ptr));
        TEST_ASSERT_EQUAL_INT8(value, (length - i) * 10);
    }
    stack_destroy(stack_ptr);
}
