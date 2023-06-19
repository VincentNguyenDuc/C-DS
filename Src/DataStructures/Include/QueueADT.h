
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

void* queue_serve(Queue *queue_pointer);

void queue_append(Queue *queue_pointer, void *data);

void queue_destroy(void *queue_pointer);

void queue_clear(Queue *queue_pointer);

short queue_is_empty(const Queue *queue_pointer);

int queue_get_length(const Queue *queue_pointer);

void* queue_peek(const Queue *queue_pointer);

