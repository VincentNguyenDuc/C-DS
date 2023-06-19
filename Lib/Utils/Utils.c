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
 * Compare 2 int pointers. 
 * Return 1 if equal, 0 otherwise
*/
int compare_int_pointers(const void *a, const void *b)
{
    int res = *(int *)a - *(int *)b;
    if (res == 0) {
        return 1;
    }
    return 0;
}