
struct Stack
{
    void** memory;
    int allocated;
    int top;

    void (*free_function)(void*);
};

typedef struct Stack Stack;

Stack* stack_init(void (*free_function)(void *item));

void stack_push(Stack* stack_pointer, void* data);

void* stack_pop(Stack* stack_pointer);

void* stack_peek(const Stack* stack_pointer);

short stack_is_empty(const Stack* stack_pointer);

int stack_get_length(const Stack* stack_pointer);

void stack_clear(Stack* stack_pointer);

short stack_contain(const Stack* stack_pointer, const void* item, int (*compare_function)(const void*, const void*));

void stack_destroy(Stack* stack_pointer);

