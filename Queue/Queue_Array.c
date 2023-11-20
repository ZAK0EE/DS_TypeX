#include <stdlib.h>
#include <string.h>
#include "Queue.h"

#ifndef Linked
//Initializes the Queue.
void CreateQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

//Append new element to the end of the queue, assuming the queue is not full.
//Pre:Queue is not full.
int Append(void* value, Queue *pq, int size)
{
    //Creating pointer and allocating memory with the size of value.
    void *ptr = malloc(size);
    if (ptr == NULL)
        return 0;
    memcpy(ptr, value, size);
    //Appending to the queue
    pq->rear = (pq->rear + 1) % MAX_QUEUE;
    pq->entry[pq->rear] = ptr;
    pq->size++;
    return 1;
}

//Serve the front (first in) element and remove it from the queue.
//Pre:Queue is not empty.
void Serve(void **element, Queue *pq, int size)
{

    //Moving the data and freeing the pointer
    memcpy(*element, pq->entry[pq->front], size);
    free(pq->entry[pq->front]);

    pq->front = (pq->front + 1) % MAX_QUEUE;
    pq->size--;
}

//Checks if queue empty
int QueueEmpty(Queue *pq)
{
    return (pq->size == 0);
}

//Checks if queue full
int QueueFull(Queue *pq)
{
    return (pq->size == MAX_QUEUE);
}

//Returns Queue size
int Queuesize(Queue *pq)
{
    return pq->size;
}
//Clears the queue
void ClearQueue(Queue *pq)
{
    for (int i = pq->front; i % MAX_QUEUE != pq->rear; i++)
        free(pq->entry[i]);
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

//Traverse over Queue elements
void TraverseQueue(Queue *pq, void(*pfun)(void*))
{
    for (int i = pq->front, size = 0; size < pq->size; i = (i + 1) % MAX_QUEUE, size++)
        (*pfun)((void*)pq->entry[i]);

}
#endif
