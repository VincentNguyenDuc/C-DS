#include "../Include/QueueADT.h"
#include <stdlib.h>
#include <string.h>

/**
 * Initialization
 */
Queue *queue_init(void (*free_function)(void *))
{
    Queue *queue = (Queue *)malloc(sizeof(*queue));
    queue->free_function = free_function;
    queue->allocated = 10;
    queue->memory = (void **)malloc(sizeof(void *) * queue->allocated);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

/**
 * Serve the element at the front
 */
void *queue_serve(Queue *queue_pointer)
{
    return queue_pointer->memory[queue_pointer->front++];
}

/**
 * Append an element to the rear
 */
void queue_append(Queue *queue_pointer, void *data)
{
    // Resize the queue
    if (queue_pointer->allocated == queue_pointer->rear)
    {
        queue_pointer->allocated *= 2;
        void **temp = (void **)malloc(sizeof(void *) * queue_pointer->allocated);
        memcpy(temp, queue_pointer->memory + queue_pointer->front, sizeof(void *) * (queue_pointer->rear - queue_pointer->front));

        free(queue_pointer->memory);
        queue_pointer->memory = temp;
        queue_pointer->rear -= queue_pointer->front;
        queue_pointer->front = 0;
    }
    queue_pointer->memory[queue_pointer->rear++] = data;
}

/**
 * Delete the queue
 */
void queue_destroy(void *queue_pointer)
{
    queue_clear(queue_pointer);
    free(((Queue *)queue_pointer)->memory);
    free(queue_pointer);
}

/**
 * Clear all elements within the queue
 */
void queue_clear(Queue *queue_pointer) 
{
    for (int i = queue_pointer->front; i < queue_pointer->rear; i++) {
        queue_pointer->free_function(queue_pointer->memory[i]);
    }
    queue_pointer->front = queue_pointer->rear = 0;
}

/**
 * Check if queue is empty
 */
short queue_is_empty(const Queue *queue_pointer)
{
    return (short) (queue_pointer->front == queue_pointer->rear);
}

/**
 * Get the length of a queue
 */
int queue_get_length(const Queue *queue_pointer)
{
    return queue_pointer->rear - queue_pointer->front;
}

/**
 * Peek at the element at the front
 */
void *queue_peek(const Queue *queue_pointer)
{
    return queue_pointer->memory[queue_pointer->front];
}
