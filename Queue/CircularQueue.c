#include <stdio.h>
#define MAX 3
typedef struct
{
        int _q[MAX];
        int front;
        int rare;
} cq;

void enqueue(cq *q, int value)
{
        if (q->front == (q->rare + 1) % MAX)
        {
                printf("Overflow!\n");
                return;
        }
        if (q->front == -1)
                q->front = q->rare = 0;
        else
                q->rare = (q->rare + 1) % MAX;
        q->_q[q->rare] = value;
        printf("Enqueue Success!\n");
}

int dequeue(cq *q)
{
        if (q->front == -1)
        {
                printf("Underflow!\n");
                return -1;
        }

        int del = q->_q[q->front];
        if (q->front == q->rare)
                q->front = q->rare = -1;
        else
                q->front = (q->front + 1) % MAX;

        return del;
}

void display(cq *q)
{
        if (q->front == -1)
        {
                printf("Underflow!\n");
                return;
        }

        printf("Circular Queue : ");
        int i = q->front;

        while (i != q->rare)
        {
                printf("%4d", q->_q[i]);
                i = (i + 1) % MAX;
        }
        printf("%4d", q->_q[i]);
        printf(" End\n");
}
int main()
{
        cq q;
        q.front = -1;
        q.rare = -1;

        int choice, value;

        while (1)
        {
                printf("\n--- Circular Queue Menu ---\n");
                printf("1. Enqueue\n");
                printf("2. Dequeue\n");
                printf("3. Display\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        printf("Enter value to enqueue: ");
                        scanf("%d", &value);
                        enqueue(&q, value);
                        break;

                case 2:
                        value = dequeue(&q);
                        if (value != -1)
                                printf("Dequeued value: %d\n", value);
                        break;

                case 3:
                        display(&q);
                        break;

                case 4:
                        printf("Exiting program...\n");
                        return 0;

                default:
                        printf("Invalid choice!\n");
                }
        }
}
