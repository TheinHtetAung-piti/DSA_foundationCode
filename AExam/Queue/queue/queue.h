#ifndef QUEUE_H
#define QUEUE_H

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void createQueue(Queue *q);
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);

#endif
