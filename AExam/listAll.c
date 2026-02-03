#include <stdio.h>
#include <stdlib.h>

/* Singly Linked List Node */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Function declarations (ADT style) */
void insertAtBeginning(Node **head, int value);
void insertAtEnd(Node **head, int value);
void deleteByValue(Node **head, int value);
void display(Node *head);
int count(Node *head);

/* Sorting methods */
void bubbleSort(Node *head);
void selectionSort(Node *head);
void insertionSort(Node **head);

/* Create node */
Node* createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at beginning */
void insertAtBeginning(Node **head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

/* Insert at end */
void insertAtEnd(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Delete by value */
void deleteByValue(Node **head, int value)
{
    Node *temp = *head, *prev = NULL;

    while (temp != NULL) {
        if (temp->data == value) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Value deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Value not found!\n");
}

/* Display list */
void display(Node *head)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* Count nodes */
int count(Node *head)
{
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

/* ---------------- SORTING METHODS ---------------- */

/* 1. Bubble Sort */
void bubbleSort(Node *head)
{
    if (head == NULL) return;

    int swapped;
    Node *ptr1;
    Node *last = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != last) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        last = ptr1;
    } while (swapped);

    printf("Bubble Sort completed.\n");
}

/* 2. Selection Sort */
void selectionSort(Node *head)
{
    Node *i, *j, *min;

    for (i = head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data)
                min = j;
        }

        if (min != i) {
            int temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
    printf("Selection Sort completed.\n");
}

/* 3. Insertion Sort */
void insertionSort(Node **head)
{
    Node *sorted = NULL;
    Node *current = *head;

    while (current != NULL) {
        Node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data)
                temp = temp->next;

            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    *head = sorted;
    printf("Insertion Sort completed.\n");
}

/* ---------------- MAIN MENU ---------------- */

int main()
{
    Node *head = NULL;
    int choice, value;

    do {
        printf("\n--- Singly Linked List (All Sorting) ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Bubble Sort\n");
        printf("6. Selection Sort\n");
        printf("7. Insertion Sort\n");
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
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;

        case 4:
            display(head);
            break;

        case 5:
            bubbleSort(head);
            break;

        case 6:
            selectionSort(head);
            break;

        case 7:
            insertionSort(&head);
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
