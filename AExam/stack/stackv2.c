#include <stdio.h>
#include <stdlib.h>

// Stack node (ADT)
struct Node {
    int data;
    struct Node *next;
};

// Check if empty
int isEmpty(struct Node *top) {
    return top == NULL;
}

// Push operation
void push(struct Node **top, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed into stack\n", value);
}

// Pop operation
int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);
    return popped;
}

// Peek operation
int peek(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Display stack
void display(struct Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Node *top = NULL;

    push(&top, 5);
    push(&top, 15);
    push(&top, 25);

    display(top);

    printf("Popped: %d\n", pop(&top));
    printf("Top element: %d\n", peek(top));

    display(top);

    return 0;
}
