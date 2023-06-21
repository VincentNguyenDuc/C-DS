#include "../Src/DataStructures/Include/ArrayStack.h"
#include "../Lib/UnityTest/unity.h"
#include "../Lib/Utils/Utils.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack* stack_ptr;

/**
 * Generate a stack for testing
*/
void generate_stack() {
    stack_ptr = stack_init();
    stack_push(stack_ptr, generate_int_pointer(10));
    stack_push(stack_ptr, generate_int_pointer(20));
    stack_push(stack_ptr, generate_int_pointer(30));
    stack_push(stack_ptr, generate_int_pointer(40));
    stack_push(stack_ptr, generate_int_pointer(50));
    stack_push(stack_ptr, generate_int_pointer(60));
}

void test_peek() {
    TEST_ASSERT_EQUAL_INT8(60, *((int *)stack_peek(stack_ptr)));
}

void test_contain() {
    TEST_ASSERT_EQUAL_INT8(0, stack_contain(stack_ptr, generate_int_pointer(100), compare_int_pointers));
    TEST_ASSERT_NOT_EQUAL_INT8(0, stack_contain(stack_ptr, generate_int_pointer(30), compare_int_pointers));
}

void test_length_push_pop() {
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
    RUN_TEST(test_peek);
    RUN_TEST(test_contain);
    RUN_TEST(test_length_push_pop);
    return UNITY_END();
}