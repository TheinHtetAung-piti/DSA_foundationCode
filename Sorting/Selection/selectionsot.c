#include <stdio.h>
#define MAX 10


int smallestPos(int arr[],int start, int size)
{
        int smallest = arr[start],pos = start;
        for(int i = start ; i < size ; i++)
        {
                if(smallest > arr[i])
                {
                        smallest = arr[i];
                        pos = i;
                }
        }
        return pos;
}

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
        int temp;
        for(int i = 0 ; i < size ; i++)
        {
                int pos = smallestPos(arr,i,size);
                temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;
                
        }
        for(int i = 0 ; i < size ; i++)
        {
                printf("%4d",arr[i]);
        }
        return 0;

}
