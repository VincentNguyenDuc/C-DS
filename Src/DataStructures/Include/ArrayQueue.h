struct ArrayQueue 
{
    void** array;
    int capacity;
    int front;
    int rear;
};

typedef struct ArrayQueue ArrayQueue;

ArrayQueue* queue_init();

void* queue_serve(ArrayQueue *queue_pointer);

void queue_append(ArrayQueue *queue_pointer, void *data);

void queue_destroy(void *queue_pointer);

void queue_clear(ArrayQueue *queue_pointer);

short queue_is_empty(const ArrayQueue *queue_pointer);

int queue_get_length(const ArrayQueue *queue_pointer);

void* queue_peek(const ArrayQueue *queue_pointer);

