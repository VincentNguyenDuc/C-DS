#include <stdlib.h>
#include <stdio.h>
#include "../Include/ArrayQueueTests.h"
#include "../../Src/DataStructures/Include/ArrayQueue.h"
#include "../../Lib/UnityTest/unity.h"
#include "../../Lib/Utils/Utils.h"

// A queue for testing 
ArrayQueue *queue_ptr;

/**
 * Generate a queue for testing
 */
void generate_queue()
{
    queue_ptr = queue_init(free);
    queue_append(queue_ptr, generate_int_pointer(10));
    queue_append(queue_ptr, generate_int_pointer(20));
    queue_append(queue_ptr, generate_int_pointer(30));
    queue_append(queue_ptr, generate_int_pointer(40));
    queue_append(queue_ptr, generate_int_pointer(50));
    queue_append(queue_ptr, generate_int_pointer(60));
}

/**
 * A simple test
 */
void array_queue_test()
{
    // length
    int length = queue_get_length(queue_ptr);
    TEST_ASSERT_EQUAL_INT8(length, 6);

    // peek
    TEST_ASSERT_EQUAL_INT8(10, *((int *)queue_peek(queue_ptr)));
    TEST_ASSERT_NOT_EQUAL_INT8(20, *((int *)queue_peek(queue_ptr)));

    // serve/append
    for (int i = 0; i < length; i++)
    {
        int value = *((int *)queue_serve(queue_ptr));
        TEST_ASSERT_EQUAL_INT8(value, (i + 1) * 10);
    }
    // is_empty
    TEST_ASSERT(queue_is_empty(queue_ptr) != 0);
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
    RUN_TEST(array_queue_test);
    return UNITY_END();
}