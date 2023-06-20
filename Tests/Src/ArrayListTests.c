#include <stdlib.h>
#include <stdio.h>
#include "../Include/ArrayListTests.h"
#include "../../Src/DataStructures/Include/ArrayList.h"
#include "../../Lib/UnityTest/unity.h"
#include "../../Lib/Utils/Utils.h"

// A list for testing
ArrayList* list_ptr;

/**
 * Generate a list for testing
 */
ArrayList* generate_list()
{
    list_ptr = list_init(10, compare_int_pointers);
    list_append(list_ptr, generate_int_pointer(10));
    list_append(list_ptr, generate_int_pointer(20));
    list_append(list_ptr, generate_int_pointer(30));
    list_append(list_ptr, generate_int_pointer(40));
    list_append(list_ptr, generate_int_pointer(50));
    list_append(list_ptr, generate_int_pointer(60));
}

/**
 * A simple test
 */
void array_list_test()
{
    // test length
    int length = list_get_length(list_ptr);
    TEST_ASSERT_EQUAL_INT8(6, length);
    // test contain
    TEST_ASSERT_EQUAL_INT8(1, list_contain(list_ptr, generate_int_pointer(40)));
    TEST_ASSERT_EQUAL_INT8(0, list_contain(list_ptr, generate_int_pointer(70)));
    // test get/append
    for (int i = 0; i < length; i++) {
        int value = *((int*) list_get_at_index(list_ptr, i));
        TEST_ASSERT_EQUAL_INT8(value, ((i + 1) * 10));
    }
    // test index
    TEST_ASSERT_EQUAL_INT8(1, list_find_index(list_ptr, generate_int_pointer(20)));
    // test insert
    list_insert_at_index(list_ptr, generate_int_pointer(80), 2);
    TEST_ASSERT_EQUAL_INT8(80, *((int *)list_get_at_index(list_ptr, 2)));
    TEST_ASSERT_EQUAL_INT8(7, list_get_length(list_ptr));
    // test delete
    list_del_at_index(list_ptr, 2);
    TEST_ASSERT_EQUAL_INT8(6, list_get_length(list_ptr));
    for (int i = 0; i < list_get_length(list_ptr); i++)
    {
        int value = *((int *)list_get_at_index(list_ptr, i));
        TEST_ASSERT_EQUAL_INT8(value, ((i + 1) * 10));
    }
    // test pop
    length = list_get_length(list_ptr);
    for (int i = 0; i < length; i++)
    {
        int value = *((int *)list_pop(list_ptr));
        TEST_ASSERT_EQUAL_INT8(((length - i) * 10), value);
    }
    TEST_ASSERT_EQUAL_INT8(0, list_get_length(list_ptr));
} 

/**
 * Set up before each test
 */
void setUp(void)
{
    generate_list();
}

/**
 * Tear down after each test
 */
void tearDown(void)
{
    list_destroy(list_ptr);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(array_list_test);
    return UNITY_END();
}