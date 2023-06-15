#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/include/stack_adt.h"

int* generateIntPointerST(int integer)
{
    int *newInt = (int *)malloc(sizeof(int));
    *newInt = integer;
    return newInt;
}

int main() {
    Stack* stack_ptr = stack_init(free);
    stack_push(stack_ptr, generateIntPointerST(10));
    stack_push(stack_ptr, generateIntPointerST(20));
    stack_push(stack_ptr, generateIntPointerST(30));
    stack_push(stack_ptr, generateIntPointerST(40));
    int length = stack_get_length(stack_ptr);
    for (int i = 0; i < length; i++) {
        printf("%d\n", *((int*)stack_pop(stack_ptr)));
    }
    return 0;
}