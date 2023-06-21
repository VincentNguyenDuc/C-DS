#include "../Src/DataStructures/Include/ArraySet.h"
#include "../Lib/UnityTest/unity.h"
#include "../Lib/Utils/Utils.h"
#include <stdlib.h>
#include <stdio.h>

ArraySet *set_ptr;

void generate_array_set() {
    set_ptr = set_init(10, compare_int_pointers);
    set_add(set_ptr, generate_int_pointer(10));
    set_add(set_ptr, generate_int_pointer(20));
    set_add(set_ptr, generate_int_pointer(30));
    set_add(set_ptr, generate_int_pointer(40));
    set_add(set_ptr, generate_int_pointer(50));
    set_add(set_ptr, generate_int_pointer(60));
}

void test_add() {
    int length = set_get_length(set_ptr);
    TEST_ASSERT_EQUAL_INT(6, length);
    set_add(set_ptr, generate_int_pointer(10));
    length = set_get_length(set_ptr);
    TEST_ASSERT_EQUAL_INT(6, length);
}

void test_remove() {
    set_remove(set_ptr, generate_int_pointer(20));
    int length = set_get_length(set_ptr);
    TEST_ASSERT_EQUAL_INT(5, length);
}

void setUp(void)
{
    generate_array_set();
}

void tearDown(void)
{
    set_destroy(set_ptr);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_remove);
    return UNITY_END();
}