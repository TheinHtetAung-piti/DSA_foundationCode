#include <stdio.h>
#include <stdlib.h>

typedef struct LL
{
        int data;
        struct LL *next;
} LL;

LL* CreateNode(int val)
{
        LL *newNode = malloc(sizeof(LL));
        newNode->data = val;
        newNode->next = NULL;

        return newNode;
}
void insertEnd(LL **head, int val)
{
        LL *newNode = CreateNode(val);

        if (*head == NULL)
        {
                *head = newNode;
        }
        else
        {
                LL *ptr = *head;
                while (ptr->next != NULL)
                {
                        ptr = ptr->next;
                }
                ptr->next = newNode;
        }
}

/* Display linked list */
void display(LL *head)
{
        if (head == NULL)
        {
                printf("Linked List is empty!\n");
                return;
        }

        printf("Linked List : ");
        LL *ptr = head;
        while (ptr != NULL)
        {
                printf("%3d -> ", ptr->data);
                ptr = ptr->next;
        }
        printf("NULL\n");
}

/* Search element */
void search(LL *head, int key)
{
        LL *ptr = head;
        int pos = 1;

        while (ptr != NULL)
        {
                if (ptr->data == key)
                {
                        printf("Element %d found at position %d\n", key, pos);
                        return;
                }
                ptr = ptr->next;
                pos++;
        }

        printf("Element %d not found!\n", key);
}

int main()
{
        LL *head = NULL;
        int choice, val;

        while (1)
        {
                printf("\n--- Linked List Menu ---\n");
                printf("1. Insert at End\n");
                printf("2. Display\n");
                printf("3. Search\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        printf("Enter value: ");
                        scanf("%d", &val);
                        insertEnd(&head, val);
                        break;

                case 2:
                        display(head);
                        break;

                case 3:
                        printf("Enter value to search: ");
                        scanf("%d", &val);
                        search(head, val);
                        break;

                case 4:
                        printf("Exiting...\n");
                        return 0;

                default:
                        printf("Invalid choice!\n");
                }
        }
}
