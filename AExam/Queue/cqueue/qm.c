#include <stdio.h>
#include "q.h"

int main()
{
    CQueue q;
    int choice, value, deleted;

    createCQueue(&q);

    do {
        printf("\n--- Circular Queue ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;

        case 2:
            deleted = dequeue(&q);
            if (deleted != -1)
                printf("Deleted element: %d\n", deleted);
            break;

        case 3:
            display(&q);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
