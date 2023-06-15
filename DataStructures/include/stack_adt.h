#ifndef C_STACK
#define C_STACK

struct Stack
{
    void** memory;
    int allocated;
    int top;

    void (*free_function)(void*);
};

typedef struct Stack Stack;

// init
Stack* stack_init(void (*free_function)(void *item));

// push
void stack_push(Stack* stack_pointer, void* data);

// pop
void* stack_pop(Stack* stack_pointer);

// peak
void* stack_peek(Stack* stack_pointer);

// is empty
short stack_is_empty(Stack* stack_pointer);

// length 
int stack_get_length(Stack* stack_pointer);

// clear
void stack_clear(Stack* stack_pointer);

// contain
short stack_contain(Stack* stack_pointer, void* item, int (*compare_function)(const void*, const void*));

void stack_destroy(Stack* stack_pointer);

#endif