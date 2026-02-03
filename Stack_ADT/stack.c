// stack.c
#include <stdio.h>
#include "stack.h"

int top = -1;
int stack[Max];

void push()
{
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    if (top == Max - 1)
    {
        printf("Overflow Condition!\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Underflow Condition!\n");
        return -1;
    }

    int value = stack[top];
    top--;
    return value;
}

int peek()
{
    if (top == -1)
    {
        printf("Underflow Condition!\n");
        return -1;
    }

    return stack[top];
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }

    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", stack[i]);
    }
    printf("\n");
}
