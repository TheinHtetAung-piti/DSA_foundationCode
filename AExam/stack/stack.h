#ifndef STACK_H
#define STACK_H

#define MAX 5

// Stack ADT
typedef struct {
    int data[MAX];
    int top;
} Stack;

// ADT function declarations
void createStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

#endif
