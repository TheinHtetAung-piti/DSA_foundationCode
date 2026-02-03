// main.c
#include <stdio.h>
#include "stack.h"
#include "stack.c"
int main()
{
        while (1)
        {
                int option;
                printf("\n1. push\n");
                printf("2. pop\n");
                printf("3. peek\n");
                printf("4. display\n");
                printf("5. exit\n");
                printf("Enter the option: ");
                scanf("%d", &option);

                switch (option)
                {
                case 1:
                        push();
                        printf("Push Success!\n");
                        break;

                case 2:
                {
                        int value = pop();
                        if (value != -1)
                                printf("Pop value is %d\n", value);
                        break;
                }

                case 3:
                {
                        int peekvalue = peek();
                        if (peekvalue != -1)
                                printf("Peek: %d\n", peekvalue);
                        break;
                }

                case 4:
                        display();
                        break;

                case 5:
                        printf("Thanks!\n");
                        return 0;

                default:
                        printf("Invalid Option!\n");
                        break;
                }
        }

        return 0;
}
