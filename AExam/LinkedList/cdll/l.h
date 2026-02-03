#ifndef CDLL_H
#define CDLL_H

// Circular Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

/* ADT function declarations */
void insertAtBeginning(Node **head, int value);
void insertAtEnd(Node **head, int value);
void insertAtPosition(Node **head, int value, int position);

void deleteFromBeginning(Node **head);
void deleteFromEnd(Node **head);
void deleteByValue(Node **head, int value);

void displayForward(Node *head);
void displayBackward(Node *head);

int count(Node *head);

/* NEW: sorting function */
void sortList(Node *head);

#endif
