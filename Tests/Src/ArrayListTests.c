#include <stdlib.h>
#include <stdio.h>
#include "../Include/ArrayListTests.h"
#include "../../Src/DataStructures/Include/ArrayList.h"
#include "../../Lib/UnityTest/unity.h"
#include "../../Lib/Utils/Utils.h"

// A vector for testing
ArrayList* list_ptr;

/**
 * Generate a queue for testing
 */
ArrayList* generate_list()
{
    list_ptr = list_init(10, free, compare_int_pointers);
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
    // pass
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