#include <stdio.h>
#include "queue.h"

void createQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

int isFull(Queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Error: Queue Overflow\n");
        return;
    }
    if (isEmpty(q))
        q->front = 0;

    q->data[++q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue Underflow\n");
        return -1;
    }

    int value = q->data[q->front++];

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return value;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->data[i]);
    printf("\n");
}
