#include <stdio.h>
#include <stdlib.h>
#include "l.h"

/* Create new node */
static Node* createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = newNode;
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

    Node *last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;

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
    Node *last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;
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
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    Node *newNode = createNode(value);

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
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

    Node *last = (*head)->prev;
    Node *temp = *head;

    *head = temp->next;
    last->next = *head;
    (*head)->prev = last;

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

    Node *last = (*head)->prev;
    Node *newLast = last->prev;

    newLast->next = *head;
    (*head)->prev = newLast;

    free(last);
}

/* Delete by value */
void deleteByValue(Node **head, int value)
{
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *curr = *head;

    do {
        if (curr->data == value) {
            if (curr->next == curr) {
                free(curr);
                *head = NULL;
                return;
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;

            if (curr == *head)
                *head = curr->next;

            free(curr);
            printf("Value deleted.\n");
            return;
        }
        curr = curr->next;
    } while (curr != *head);

    printf("Value not found!\n");
}

/* Display forward */
void displayForward(Node *head)
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

/* Display backward */
void displayBackward(Node *head)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head->prev;
    Node *last = temp;

    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != last);

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

/* SORT (Bubble sort – swap data) */
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
