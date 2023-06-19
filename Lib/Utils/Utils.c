#include "./Utils.h"
#include <stdlib.h>

/**
 * Generate int pointer from an int value
 */
int *generate_int_pointer(int integer)
{
    int *newInt = (int *)malloc(sizeof(int));
    *newInt = integer;
    return newInt;
}

/**
 * Compare 2 int pointers
*/
int compare_int_pointers(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}