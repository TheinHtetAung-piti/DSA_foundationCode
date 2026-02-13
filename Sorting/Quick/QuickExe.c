#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int start,int end)
{
        int pivot = arr[end];
        int i = start - 1;
        for (int j = start; j < end; j++)
        {
                if(arr[j] < pivot)
                {
                        i++;
                        swap(&arr[i], &arr[j]);
                }
        }

        swap(&arr[i+1],&arr[end]);

        return i+1;
        
}
void quickSort(int arr[],int start , int end)
{
        if(end <= start) return;
        int piv = partition(arr,start,end);
        quickSort(arr,start,piv-1);
        quickSort(arr,piv+1,end);
}
int main()
{
        printf("Enter the size of arr : ");
        int size;
        scanf("%d",&size);
        int  arr[size];
        printf("Enter %d element : ",size);
        for (int i = 0; i < size; i++)
        {
                scanf("%d",&arr[i]);
        }
        
        quickSort(arr,0,size);
        printf("\nafter sorted!");
        for (int i = 0; i < size; i++)
        {
                /* code */printf("%4d",arr[i]);
        }
        
        return 0;
        
}