#include "./UnityUnitTests/src/unity.h"
#include "./include/StackTests.h"

void setUp(void) {
    /* Init calls here. */
}    
void tearDown(void) {
    /* Clean-up calls here. */
} 

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(stack_unit_tests);
    return UNITY_END();
}