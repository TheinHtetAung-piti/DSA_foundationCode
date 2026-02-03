#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rare = -1;

void insert(int num)
{
        if (rare == MAX - 1)
        {
                printf("Overflow!\n");
                return;
        }
        if (front == -1 && rare == -1)
        {
                front = 0;
        }
        rare++;
        queue[rare] = num;
        printf("Data Added!\n");
}

int delete()
{
        if (front == -1 || front > rare)
        {
                printf("Underflow!\n");
                return -1;
        }
        return queue[front--];
}

int peek()
{
        if (front == -1 || front > rare)
        {
                printf("Underflow!\n");
                return -1;
        }
        return queue[front];
}

void display()
{
        if (front == -1 || front > rare)
        {
                printf("Underflow!\n");
                return;
        }
        for (int i = front; i <= rare; i++)
        {
                printf("%4d", queue[i]);
        }
        printf("\n");
}
int main()

{
        int option;
start:
        printf("\n1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exist\n");
        printf("Enter option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
                int num;
                printf("Enter the data : ");
                scanf("%d", &num);
                insert(num);
                break;
        case 2:
                int del = delete();
                if (del == -1)
                        break;
                printf("This is the delete Data : %d\n", del);
                break;
        case 3:

                int pek = peek();
                if (pek == -1)
                        break;
                printf("This is the peek Data : %d\n", pek);
                break;
        case 4:
                display();
                break;
        case 5:
                printf("Thanks!");
                return 0;

        default:
                printf("Invlaid option\n");
                break;
        }
        printf("%d \t %d\n", front, rare);
        goto start;
        return 0;
}