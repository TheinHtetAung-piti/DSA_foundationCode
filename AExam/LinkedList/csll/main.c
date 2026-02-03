#include <stdio.h>
#include "l.h"

int main()
{
    Node *head = NULL;
    int choice, value, position;

    do {
        printf("\n--- Circular Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Display\n");
        printf("8. Count Nodes\n");
        printf("9. Sort List\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, value, position);
            break;

        case 4:
            deleteFromBeginning(&head);
            break;

        case 5:
            deleteFromEnd(&head);
            break;

        case 6:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;

        case 7:
            display(head);
            break;

        case 8:
            printf("Total nodes: %d\n", count(head));
            break;

        case 9:
            sortList(head);
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
