#include "./UnityUnitTests/src/unity.h"
#include "./include/stack_tests.h"

void setUp(void) {}    /* Unit init calls here. */
void tearDown(void) {} /* Unit clean-up calls here. */

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(stack_unit_tests);
    return UNITY_END();
}