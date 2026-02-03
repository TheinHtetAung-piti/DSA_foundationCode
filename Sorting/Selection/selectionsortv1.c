#include <stdio.h>
#define MAX 10
int main()
{
        int arr[MAX];
        int size;
        printf("Enter the size of array : ");
        scanf("%d", &size);
        for (int i = 0; i < size; i++)
        {
                printf("Enter index [%d] : ", i);
                scanf("%d", &arr[i]);
        }

        printf("Sotring is running : \n");

        int pos = 0, temp;
        for (int i = 0; i < size; i++)
        {
                int smallest = arr[i];
                pos = i;
                for (int j = i; j < size; j++)
                {
                        if (smallest > arr[j])
                        {
                                smallest = arr[j];
                                pos = j;
                        }
                }
                temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
        }

        for (int i = 0; i < size; i++)
        {
                printf("%4d", arr[i]);
        }
        return 0;
}