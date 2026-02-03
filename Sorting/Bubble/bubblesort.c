#include<stdio.h>

int main()
{
        int size , arr[15];
        printf("Enter the size : ");
        scanf("%d",&size);

        for(int i = 0 ; i < size ; i++)
        {
                printf("Enter Index[%d] : ",i);
                scanf("%d",&arr[i]);
        }

        printf("Bullbe is running ! \n");
        for( int i = 0 ; i < size ; i ++)
        {
                for(int j = 0 ; j < size - i - 1; j++)
                {
                        int temp ;
                        if(arr[j] < arr[j+1])
                        {
                                temp = arr[j+1];
                                arr[j+1] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
        printf("\nSotring End ! \n");

        for(int i = 0 ; i < size ; i++)
        {
                printf("%4d",arr[i]);
        }
}