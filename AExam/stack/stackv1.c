#include <stdio.h>
#define MAX 5   // stack size

// Stack ADT
struct Stack {
    int data[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push operation
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->data[++s->top] = value;
    printf("%d pushed into stack\n", value);
}

// Pop operation
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->data[s->top--];
}

// Peek operation
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

// Display stack
void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    display(&s);

    return 0;
}
