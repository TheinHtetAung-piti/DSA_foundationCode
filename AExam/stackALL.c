#include <stdio.h>
#include <stdlib.h>

#define MAX 5

/* Stack structure */
typedef struct {
    int data[MAX];
    int top;
} Stack;

/* Stack function declarations */
void createStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

/* Initialize stack */
void createStack(Stack *s)
{
    s->top = -1;
}

/* Check empty */
int isEmpty(Stack *s)
{
    return (s->top == -1);
}

/* Check full */
int isFull(Stack *s)
{
    return (s->top == MAX - 1);
}

/* Push */
void push(Stack *s, int value)
{
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }

    s->data[++s->top] = value;
    printf("Pushed %d\n", value);
}

/* Pop */
int pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }

    return s->data[s->top--];
}

/* Peek */
int peek(Stack *s)
{
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }

    return s->data[s->top];
}

/* Display stack */
void display(Stack *s)
{
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom): ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->data[i]);
    printf("\n");
}

/* ================= MAIN MENU ================= */

int main()
{
    Stack s;
    int choice, value;

    createStack(&s);

    do {
        printf("\n--- STACK (ONE FILE) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(&s, value);
            break;

        case 2:
            value = pop(&s);
            if (value != -1)
                printf("Popped element: %d\n", value);
            break;

        case 3:
            value = peek(&s);
            if (value != -1)
                printf("Top element: %d\n", value);
            break;

        case 4:
            display(&s);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
