#include <stdio.h>
int main()
{
        int size, start, end, found = 0, mid;
        printf("Enter size of array : ");
        scanf("%d", &size);
        int arr[size];
        printf("Enter array %d element : ", size);
        for (int i = 0; i < size; i++)
        {
                scanf("%d", &arr[i]);
        }

        printf("\nDisplay : ");
        for (int i = 0; i < size; i++)
                printf("%4d", arr[i]);

        printf("\n");

        printf("Enter target value : ");
        int target;
        scanf("%d", &target);

        int start = 0, end = size - 1, mid, found = 0;
        while (start <= end)
        {
                mid = (start + end) / 2;
                if (arr[mid] == target)
                {
                        printf("Element found at %d index !", mid);
                        found = 1;
                        break;
                }
                else if (arr[mid] > target)
                {
                        end = mid - 1;
                }
                else
                {
                        start = mid + 1;
                }
        }
        if (!found)
                printf("Element not found!\n");
        return 0;
}