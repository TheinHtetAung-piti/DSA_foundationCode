#include <stdio.h>
#include <stdlib.h>
#include "l.h"

/* Create node */
static Node* createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

/* Insert at beginning */
void insertAtBeginning(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

/* Insert at end */
void insertAtEnd(Node **head, int value)
{
    if (*head == NULL) {
        insertAtBeginning(head, value);
        return;
    }

    Node *newNode = createNode(value);
    Node *temp = *head;

    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

/* Insert at position */
void insertAtPosition(Node **head, int value, int position)
{
    int n = count(*head);

    if (position < 1 || position > n + 1) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;

    Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete from beginning */
void deleteFromBeginning(Node **head)
{
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    Node *last = *head;

    while (last->next != *head)
        last = last->next;

    *head = temp->next;
    last->next = *head;
    free(temp);
}

/* Delete from end */
void deleteFromEnd(Node **head)
{
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    Node *prev = NULL;
    Node *curr = *head;

    while (curr->next != *head) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = *head;
    free(curr);
}

/* Delete by value */
void deleteByValue(Node **head, int value)
{
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *curr = *head;
    Node *prev = NULL;

    do {
        if (curr->data == value) {
            if (curr->next == curr) {
                free(curr);
                *head = NULL;
                return;
            }

            if (curr == *head) {
                deleteFromBeginning(head);
                return;
            }

            prev->next = curr->next;
            free(curr);
            printf("Value deleted.\n");
            return;
        }

        prev = curr;
        curr = curr->next;

    } while (curr != *head);

    printf("Value not found!\n");
}

/* Display list */
void display(Node *head)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

/* Count nodes */
int count(Node *head)
{
    if (head == NULL)
        return 0;

    int cnt = 0;
    Node *temp = head;

    do {
        cnt++;
        temp = temp->next;
    } while (temp != head);

    return cnt;
}

/* Sort list (Bubble Sort – swap data) */
void sortList(Node *head)
{
    if (head == NULL || head->next == head)
        return;

    int swapped;
    Node *ptr1;
    Node *last = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        do {
            if (ptr1->next != last && ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != last);

        last = ptr1;
    } while (swapped);

    printf("List sorted successfully.\n");
}
