#ifndef ARRAY_H
#define ARRAY_H

#define MAX 100

typedef struct
{
        int data[MAX];
        int size;
} Array;

void createArray(Array *a);
void displayArray(Array *a);
void bubbleSort(Array *a);
void insertionSort(Array *a);

#endif
