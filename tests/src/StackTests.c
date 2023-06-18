#include "../include/StackTests.h"
#include "../../lib/DataStructures/include/StackADT.h"
#include "../UnityUnitTests/src/unity.h"
#include "../utils/Utils.h"
#include <stdlib.h>
#include <stdio.h>

Stack* stack_ptr;

/**
 * Generate a stack for testing
*/
void generate_stack() {
    stack_ptr = stack_init(free);
    stack_push(stack_ptr, generate_int_pointer(10));
    stack_push(stack_ptr, generate_int_pointer(20));
    stack_push(stack_ptr, generate_int_pointer(30));
    stack_push(stack_ptr, generate_int_pointer(40));
    stack_push(stack_ptr, generate_int_pointer(50));
    stack_push(stack_ptr, generate_int_pointer(60));
}

/**
 * A simple test 
*/
void stack_simple_test() {
    int length = stack_get_length(stack_ptr);
    for (int i = 0; i < length; i++){
        int value = *((int *)stack_pop(stack_ptr));
        TEST_ASSERT_EQUAL_INT8(value, (length - i) * 10);
    }
}

/**
 * A complex test
 */
void stack_complex_test()
{
    int length = stack_get_length(stack_ptr);
    for (int i = 0; i < length; i++)
    {
        int value = *((int *)stack_pop(stack_ptr));
        TEST_ASSERT_EQUAL_INT8(value, (length - i) * 10);
    }
}

void setUp(void)
{
    generate_stack();
}

void tearDown(void)
{
    stack_destroy(stack_ptr);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(stack_simple_test);
    RUN_TEST(stack_complex_test);
    return UNITY_END();
}