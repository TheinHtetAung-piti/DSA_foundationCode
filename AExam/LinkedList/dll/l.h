#ifndef DLL_H
#define DLL_H

// Doubly linked list node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// ADT function declarations
void insertAtBeginning(Node **head, int value);
void insertAtEnd(Node **head, int value);
void insertAtPosition(Node **head, int value, int position);

void deleteFromBeginning(Node **head);
void deleteFromEnd(Node **head);
void deleteByValue(Node **head, int value);

void displayForward(Node *head);
void displayBackward(Node *head);

int count(Node *head);

/* NEW: sort function */
void sortList(Node *head);

#endif
