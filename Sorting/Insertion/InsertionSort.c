#include <stdio.h>
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

        printf("Insertion Sort is running : \n");

        int j, key;
        for (int i = 1; i < size; i++)
        {
                int key = arr[i];
                j = i - 1;

                while (j >= 0 && arr[j] > key)
                {
                        arr[j + 1] = arr[j];
                        j--;
                }
                arr[j + 1] = key;
        }

        printf("\nArray after sorting : \n");
        for (int i = 0; i < size; i++)
        {
                printf("%4d", arr[i]);
        }
        printf("\n");
        return 0;
}