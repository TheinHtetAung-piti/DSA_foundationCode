#include <stdio.h>
#include "array.h"
#include "array.c"

int main()
{
        Array arr;
        arr.size = 0;

        int choice;

        do
        {
                printf("\n1.Create Array\n");
                printf("2.display Array\n");
                printf("3.Bubble Sort\n");
                printf("4.Insertion Sort\n");
                printf("5.Exit\n");
                printf("Enter option : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                        createArray(&arr);
                        break;
                case 2:
                        displayArray(&arr);
                        break;
                case 3:
                        bubbleSort(&arr);
                        displayArray(&arr);
                        break;
                case 4:
                        insertionSort(&arr);
                        displayArray(&arr);
                        break;
                case 5:
                        printf("Thanks!\n");
                        break;
                default:
                        printf("Invalid choice!\n");
                }
        } while (choice != 5);

        return 0;
}
