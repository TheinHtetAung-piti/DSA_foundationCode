#include <stdio.h>
int findSmallestIndex(int arr[], int start, int size);
int main()
{
        int size;
        printf("Enter size of array: ");
        scanf("%d", &size);

        int arr[size];
        printf("Enter %d elements : ", size);
        for (int i = 0; i < size; i++)
        {
                scanf("%d", &arr[i]);
        }
        printf("\nArray before sorting : \n");
        for (int i = 0; i < size; i++)
        {
                printf("%4d", arr[i]);
        }
        printf("\n");

        int temp;
        printf("Selection Sort is running : \n");
        for(int i = 0 ; i < size ; i++)
        {
                int smallestIndex = findSmallestIndex(arr,i,size);
                
                temp = arr[i];
                arr[i] = arr[smallestIndex];
                arr[smallestIndex] = temp;
        }

                printf("\nArray after sorting : \n");
        for (int i = 0; i < size; i++)
        {
                printf("%4d", arr[i]);
        }
        printf("\n");
}

int findSmallestIndex(int arr[], int start, int size)
{
        int minIndex = start;
        int minVal = arr[start];
        for(int i = start ; i < size ; i++ )
        {
                if(minVal > arr[i])
                {
                        minVal = arr[i];
                        minIndex = i;
                }
        }

        return minIndex;
}