#ifndef PQUEUE_H
#define PQUEUE_H

#define MAX 5

typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PQueue;

void createPQueue(PQueue *pq);
int isEmpty(PQueue *pq);
int isFull(PQueue *pq);
void enqueue(PQueue *pq, int value, int priority);
int dequeue(PQueue *pq);
void display(PQueue *pq);

#endif
