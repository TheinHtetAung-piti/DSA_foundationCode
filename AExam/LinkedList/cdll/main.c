#include <stdio.h>
#include "l.h"

int main()
{
    Node *head = NULL;
    int choice, value, position;

    do {
        printf("\n--- Circular Doubly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete by Value\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Count Nodes\n");
        printf("10. Sort List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
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
            displayForward(head);
            break;

        case 8:
            displayBackward(head);
            break;

        case 9:
            printf("Total nodes: %d\n", count(head));
            break;

        case 10:
            sortList(head);
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
