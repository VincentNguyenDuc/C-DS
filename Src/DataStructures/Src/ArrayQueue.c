#include "../Include/ArrayQueue.h"
#include <stdlib.h>
#include <string.h>

/**
 * Initialization
 */
ArrayQueue* queue_init()
{
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(*queue));
    queue->capacity = 10;
    queue->array = (void **)malloc(sizeof(void *) * queue->capacity);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

/**
 * Serve the element at the front
 */
void *queue_serve(ArrayQueue *queue_pointer)
{
    return queue_pointer->array[queue_pointer->front++];
}

/**
 * Append an element to the rear
 */
void queue_append(ArrayQueue *queue_pointer, void *data)
{
    // Resize the queue
    if (queue_pointer->capacity == queue_pointer->rear)
    {
        queue_pointer->capacity *= 2;
        void **temp = (void **)malloc(sizeof(void *) * queue_pointer->capacity);
        memcpy(temp, queue_pointer->array + queue_pointer->front, sizeof(void *) * (queue_pointer->rear - queue_pointer->front));

        free(queue_pointer->array);
        queue_pointer->array = temp;
        queue_pointer->rear -= queue_pointer->front;
        queue_pointer->front = 0;
    }
    queue_pointer->array[queue_pointer->rear++] = data;
}

/**
 * Delete the queue
 */
void queue_destroy(void *queue_pointer)
{
    queue_clear(queue_pointer);
    free(((ArrayQueue *)queue_pointer)->array);
    free(queue_pointer);
}

/**
 * Clear all elements within the queue
 */
void queue_clear(ArrayQueue *queue_pointer) 
{
    for (int i = queue_pointer->front; i < queue_pointer->rear; i++) {
        free(queue_pointer->array[i]);
    }
    queue_pointer->front = queue_pointer->rear = 0;
}

/**
 * Check if queue is empty
 */
short queue_is_empty(const ArrayQueue *queue_pointer)
{
    return (short) (queue_pointer->front == queue_pointer->rear);
}

/**
 * Get the length of a queue
 */
int queue_get_length(const ArrayQueue *queue_pointer)
{
    return queue_pointer->rear - queue_pointer->front;
}

/**
 * Peek at the element at the front
 */
void *queue_peek(const ArrayQueue *queue_pointer)
{
    return queue_pointer->array[queue_pointer->front];
}
