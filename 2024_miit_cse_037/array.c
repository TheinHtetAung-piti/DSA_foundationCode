#include <stdio.h>
#include "array.h"

void createArray(Array *a)
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &a->size);

    printf("Enter elements: ");
    for (i = 0; i < a->size; i++)
    {
        scanf("%d", &a->data[i]);
    }
}

void displayArray(Array *a)
{
    int i;

    if (a->size == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements: ");
    for (i = 0; i < a->size; i++)
    {
        printf("%d ", a->data[i]);
    }
    printf("\n");
}

void bubbleSort(Array *a)
{
    int i, j, temp;

    for (i = 0; i < a->size - 1; i++)
    {
        for (j = 0; j < a->size - 1 - i; j++)
        {
            if (a->data[j] > a->data[j + 1])
            {
                temp = a->data[j];
                a->data[j] = a->data[j + 1];
                a->data[j + 1] = temp;
            }
        }
    }
}

void insertionSort(Array *a)
{
    int i, key, j;

    for (i = 1; i < a->size; i++)
    {
        key = a->data[i];
        j = i - 1;

        while (j >= 0 && a->data[j] > key)
        {
            a->data[j + 1] = a->data[j];
            j--;
        }
        a->data[j + 1] = key;
    }
}
