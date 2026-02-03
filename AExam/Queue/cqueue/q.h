#ifndef CQUEUE_H
#define CQUEUE_H

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CQueue;

void createCQueue(CQueue *q);
int isEmpty(CQueue *q);
int isFull(CQueue *q);
void enqueue(CQueue *q, int value);
int dequeue(CQueue *q);
void display(CQueue *q);

#endif
