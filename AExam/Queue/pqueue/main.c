#include <stdio.h>
#include ".h"

int main() {
    PQueue pq;
    createPQueue(&pq);

    enqueue(&pq, 10, 3);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 2);

    display(&pq);

    printf("Dequeued: %d\n", dequeue(&pq));
    display(&pq);

    return 0;
}
