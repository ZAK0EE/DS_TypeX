#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "Settings.h"

#ifdef Linked
typedef struct queuenode
{
    void *entry;
    struct queuenode* next;

}QueueNode;

typedef struct Queue
{
    QueueNode* front;
    QueueNode* rear;
    int size;
}Queue;
#else
#define MAX_QUEUE MAX_ELEMENTS
typedef struct queue
{
    int front;
    int rear;
    int size;
    void* entry[MAX_QUEUE];
}Queue;
#endif

//Initializes the Queue.
void CreateQueue(Queue *);

//Append new element to the end of the queue, assuming the queue is not full.
//Pre:Queue is not full.
int Append(void*, Queue *, int);

//Serve the front (first in) element and remove it from the queue.
//Pre:Queue is not empty.
void Serve(void **, Queue *, int);

//Checks if queue empty
int QueueEmpty(Queue *);

//Checks if queue full
int QueueFull(Queue *);

//Returns Queue size
int Queuesize(Queue *);

//Clears the queue
//Pre:The Queue is not empty.
void ClearQueue(Queue *);

//Traverse over Queue elements
void TraverseQueue(Queue *, void(*pfun)(void*));
#endif // QUEUE_H_INCLUDED
