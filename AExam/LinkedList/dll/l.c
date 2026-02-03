#include <stdio.h>
#include <stdlib.h>
#include "l.h"

/* Create new node */
static Node* createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* Insert at beginning */
void insertAtBeginning(Node **head, int value)
{
    Node *newNode = createNode(value);

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }

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
    newNode->prev = temp;
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
    newNode->prev = temp;

    if (temp->next != NULL)
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

    Node *temp = *head;
    *head = temp->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

/* Delete from end */
void deleteFromEnd(Node **head)
{
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = *head;

    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

/* Delete by value */
void deleteByValue(Node **head, int value)
{
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = *head;

    while (temp != NULL) {
        if (temp->data == value) {

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                *head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
            printf("Value deleted.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Value not found!\n");
}

/* Display forward */
void displayForward(Node *head)
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

/* Display backward */
void displayBackward(Node *head)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

/* Count nodes */
int count(Node *head)
{
    int cnt = 0;
    while (head != NULL) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

/* Sort list (Bubble Sort – swap data) */
void sortList(Node *head)
{
    if (head == NULL)
        return;

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

    printf("List sorted successfully.\n");
}
