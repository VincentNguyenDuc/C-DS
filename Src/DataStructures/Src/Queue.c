#include "../Include/QueueADT.h"
#include <stdlib.h>

Queue* queue_init(void (*free_function)(void *)) {
    Queue* queue = (Queue*) malloc(sizeof(*queue));
    queue->free_function = free_function;
    queue->allocated = 10;
    queue->memory = (void **) malloc(sizeof(void *) * queue->allocated);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

