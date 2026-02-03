#include <stdio.h>
#include "q.h"

/* Initialize circular queue */
void createCQueue(CQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

/* Check empty */
int isEmpty(CQueue *q)
{
    return (q->front == -1);
}

/* Check full */
int isFull(CQueue *q)
{
    return ((q->rear + 1) % MAX == q->front);
}

/* Enqueue */
void enqueue(CQueue *q, int value)
{
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = value;
    printf("Inserted %d\n", value);
}

/* Dequeue */
int dequeue(CQueue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int value = q->data[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

/* Display queue */
void display(CQueue *q)
{
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    int i = q->front;

    printf("Queue elements: ");
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
