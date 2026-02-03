#include <stdio.h>
#include "stack.h"

// Initialize stack
void createStack(Stack *s) {
    s->top = -1;
}

// Check empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Check full
int isFull(Stack *s) {
    return (s->top == MAX - 1);
}

// Push
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Error: Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
