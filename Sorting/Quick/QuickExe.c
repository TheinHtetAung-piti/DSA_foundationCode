#include <stdio.h>

void swap(int *a, int *b)
{
        int temp = *b;
        *b = *a;
        *a = temp;
}
int partition(int arr[], int start, int end)
{
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end ; j++)
        {
                if (arr[j] < pivot)
                {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }
        swap(&arr[i + 1], &arr[end]);
        return i + 1;
}
void quickSort(int arr[], int start, int end)
{
        if (end <= start)
        {
                return;
        }

        int pivot = partition(arr,start,end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
}
int main()
{
        int size;
        printf("Enter the size of arr : ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter %d element : ", size);
        for (int i = 0; i < size; i++)
        {
                scanf("%d", &arr[i]);
        }

        printf("Before Sort : ");
        for (int i = 0; i < size; i++)
        {
                printf("%4d", arr[i]);
        }
        quickSort(arr, 0, size);
        printf("\nAfter Sorted : ");
        for (int i = 0; i < size; i++)
        {
                printf("%4d", arr[i]);
        }
        return 0;
}