#include <stdlib.h>
#include <stdio.h>
#include "../Src/DataStructures/Include/ArrayQueue.h"
#include "../Lib/UnityTest/unity.h"
#include "../Lib/Utils/Utils.h"

// A queue for testing 
ArrayQueue *queue_ptr;

/**
 * Generate a queue for testing
 */
void generate_queue()
{
    queue_ptr = queue_init();
    queue_append(queue_ptr, generate_int_pointer(10));
    queue_append(queue_ptr, generate_int_pointer(20));
    queue_append(queue_ptr, generate_int_pointer(30));
    queue_append(queue_ptr, generate_int_pointer(40));
    queue_append(queue_ptr, generate_int_pointer(50));
    queue_append(queue_ptr, generate_int_pointer(60));
}

void test_length() {
    int length = queue_get_length(queue_ptr);
    TEST_ASSERT_EQUAL_INT8(length, 6);
}

void test_peek() {
    TEST_ASSERT_EQUAL_INT8(10, *((int *)queue_peek(queue_ptr)));
    TEST_ASSERT_NOT_EQUAL_INT8(20, *((int *)queue_peek(queue_ptr)));
}

void test_serve_append() {
    int length = queue_get_length(queue_ptr);
    for (int i = 0; i < length; i++)
    {
        int value = *((int *)queue_serve(queue_ptr));
        TEST_ASSERT_EQUAL_INT8(value, (i + 1) * 10);
    }
}

void test_is_empty() {
    TEST_ASSERT(!queue_is_empty(queue_ptr));
    test_serve_append();
    TEST_ASSERT(queue_is_empty(queue_ptr));
}

/**
 * Set up before each test
 */
void setUp(void)
{
    generate_queue();
}

/**
 * Tear down after each test
 */
void tearDown(void)
{
    queue_destroy(queue_ptr);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_length);
    RUN_TEST(test_peek);
    RUN_TEST(test_serve_append);
    RUN_TEST(test_is_empty);
    return UNITY_END();
}