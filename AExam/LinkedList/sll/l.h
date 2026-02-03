#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* ADT function declarations */
void insertAtBeginning(Node **head, int value);
void insertAtEnd(Node **head, int value);
void insertAtPosition(Node **head, int value, int position);

void deleteFromBeginning(Node **head);
void deleteFromEnd(Node **head);
void deleteByValue(Node **head, int value);

void display(Node *head);
int count(Node *head);

/* NEW: sort function */
void sortList(Node *head);

#endif
