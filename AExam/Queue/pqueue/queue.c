#include <stdio.h>
#include "queue.h"

void createPQueue(PQueue *pq) {
    pq->size = 0;
}

int isEmpty(PQueue *pq) {
    return (pq->size == 0);
}

int isFull(PQueue *pq) {
    return (pq->size == MAX);
}

void enqueue(PQueue *pq, int value, int priority) {
    if (isFull(pq)) {
        printf("Error: Priority Queue Overflow\n");
        return;
    }

    int i = pq->size - 1;

    while (i >= 0 && pq->priority[i] > priority) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }

    pq->data[i + 1] = value;
    pq->priority[i + 1] = priority;
    pq->size++;
}

int dequeue(PQueue *pq) {
    if (isEmpty(pq)) {
        printf("Error: Priority Queue Underflow\n");
        return -1;
    }

    return pq->data[--pq->size];
}

void display(PQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++)
        printf("Value: %d  Priority: %d\n", pq->data[i], pq->priority[i]);
}
