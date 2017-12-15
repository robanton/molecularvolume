#include "queue.h"
#include <stdlib.h>

// Make a new queue with maximum capacity of ``capacity`` Triples
struct Queue* newQueue(int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = 0;
    queue->size = 0;
    queue->rear = 0;
    queue->capacity = capacity;
    queue->items = (struct Triple*)malloc(capacity*sizeof(struct Triple));
    return queue;
}

// Check if the queue is full
int isFull(struct Queue* queue)
{
    if (queue->capacity == queue->size){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct Queue* queue)
{
    if (queue->size == 0){
        return 1;
    } else {
        return 0;
    }
    
}

// Add a Triple to the queue
int append(struct Triple coords, struct Queue* queue)
{
    if (isFull(queue)){
        return 1; // error; queue is full
    }
    // Add the item to the rear of the queue
    // wrapping around to the beginning of the array if need be
    queue->items[queue->rear % queue->capacity]  = coords;
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->size += 1;
    return 0;
}

// Always check that the queue is not empty before calling this!
struct Triple pop(struct Queue* queue)
{
    struct Triple item = queue->items[queue->front];
    queue->front = (queue->front+1)%(queue->capacity);
    if (queue->size > 0){
        queue->size -= 1;
    }
    return item;
}
