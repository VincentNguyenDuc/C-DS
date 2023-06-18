
struct Queue 
{
    void** memory;
    int allocated;
    int front;
    int rear;

    void (*free_function)(void*);
};

typedef struct Queue Queue;

Queue* queue_init(void (*free_function)(void*));

void queue_serve(Queue *queue_pointer, void *data);

void *queue_append(Queue *queue_pointer);

void queue_destroy(void *queue_pointer);

void queue_clear(Queue *queue_pointer);

int queue_is_empty(Queue *queue_pointer);

int queue_get_length(Queue *queue_pointer);

void* queue_peek(Queue *queue_pointer);

