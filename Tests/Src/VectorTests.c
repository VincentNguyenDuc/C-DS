#include <stdlib.h>
#include <stdio.h>
#include "../Include/VectorTests.h"
#include "../../Src/DataStructures/Include/Vector.h"
#include "../../Lib/UnityTest/unity.h"
#include "../../Lib/Utils/Utils.h"

// A vector for testing
Vector* vector_ptr;

/**
 * Generate a queue for testing
 */
Vector* generate_vector()
{
    vector_ptr = vector_init(10, free, compare_int_pointers);
    vector_append(vector_ptr, generate_int_pointer(10));
    vector_append(vector_ptr, generate_int_pointer(20));
    vector_append(vector_ptr, generate_int_pointer(30));
    vector_append(vector_ptr, generate_int_pointer(40));
    vector_append(vector_ptr, generate_int_pointer(50));
    vector_append(vector_ptr, generate_int_pointer(60));
}

/**
 * A simple test
 */
void vector_test()
{
    
}

/**
 * Set up before each test
 */
void setUp(void)
{
    generate_vector();
}

/**
 * Tear down after each test
 */
void tearDown(void)
{
    
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(vector_test);
    return UNITY_END();
}