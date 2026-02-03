#include <stdio.h>
#include "stack.h"

int main() {
    Stack s;

    createStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    display(&s);

    return 0;
}
