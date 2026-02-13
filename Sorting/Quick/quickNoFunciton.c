#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high]; // last element as pivot
    int i = low - 1;

    printf("\nPivot = %d\n", pivot);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
            printArray(arr, n); // print after each swap
        }
    }

    // place pivot in correct position
    swap(&arr[i + 1], &arr[high]);
    printArray(arr, n); // print after pivot swap

    printf("\nreturn i : %d\n", i + 1);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, n);
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1, n);

    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
