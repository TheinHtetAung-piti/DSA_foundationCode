// stack.h
#ifndef STACK_H
#define STACK_H

#define Max 10

extern int top;
extern int stack[Max];

void push();
int pop();
int peek();
void display();

#endif
