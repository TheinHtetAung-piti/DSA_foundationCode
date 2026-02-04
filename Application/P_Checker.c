#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Stack implementation
typedef struct {
        char data[MAX];
        int top;
} Stack;

void init(Stack *s) {
        s->top = -1;
}

/**
 * Checks if the given stack is empty.
 *
 * @param s Pointer to the stack structure to be checked.
 * @return Returns 1 if the stack is empty, otherwise returns 0.
 */
int isEmpty(Stack *s) {
        return s->top == -1;
}

int isFull(Stack *s) {
        return s->top == MAX - 1;
}

void push(Stack *s, char c) {
        if (!isFull(s)) {
                s->data[++(s->top)] = c;
        }
}

char pop(Stack *s) {
        if (!isEmpty(s)) {
                return s->data[(s->top)--];
        }
        return '\0';
}

char peek(Stack *s) {
        if (!isEmpty(s)) {
                return s->data[s->top];
        }
        return '\0';
}

int isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
                   (open == '{' && close == '}') ||
                   (open == '[' && close == ']');
}

int isBalanced(const char *expr) {
        Stack s;
        init(&s);
        for (int i = 0; expr[i] != '\0'; i++) {
                char c = expr[i];
                if (c == '(' || c == '{' || c == '[') {
                        push(&s, c);
                } else if (c == ')' || c == '}' || c == ']') {
                        if (isEmpty(&s) || !isMatchingPair(pop(&s), c)) {
                                return 0;
                        }
                }
        }
        return isEmpty(&s);
}

int main() {
        char expr[MAX];
        printf("Enter an expression: ");
        fgets(expr, MAX, stdin);
        expr[strcspn(expr, "\n")] = '\0';

        if (isBalanced(expr)) {
                printf("Parentheses are balanced.\n");
        } else {
                printf("Parentheses are NOT balanced.\n");
        }
        return 0;
}