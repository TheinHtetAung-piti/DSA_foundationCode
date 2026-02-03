#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    createQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}
