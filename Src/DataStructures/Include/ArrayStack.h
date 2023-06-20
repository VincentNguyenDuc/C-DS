struct ArrayStack
{
    void** memory;
    int allocated;
    int top;

    void (*free_function)(void*);
};

typedef struct ArrayStack ArrayStack;

ArrayStack* stack_init(void (*free_function)(void *item));

void stack_push(ArrayStack* stack_pointer, void* data);

void* stack_pop(ArrayStack* stack_pointer);

void* stack_peek(const ArrayStack* stack_pointer);

short stack_is_empty(const ArrayStack* stack_pointer);

int stack_get_length(const ArrayStack* stack_pointer);

void stack_clear(ArrayStack* stack_pointer);

short stack_contain(const ArrayStack* stack_pointer, const void* item, int (*compare_function)(const void*, const void*));

void stack_destroy(ArrayStack* stack_pointer);

