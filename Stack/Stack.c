#include<stdio.h>
#define Max 10
int top = -1 ;
int stack[Max];

void push()
{
        int value ; 
        printf("Enter the vlaue : ");
        scanf("%d",&value);
        if(top == Max-1)
        {
                printf("Overflow Condition!\n");      
        }
        else
        {
        top++;
        stack[top] = value;
        }

}

int pop()
{
        if(top == -1)
        {
                printf("Underflow Condition!\n");
                return -1;
        }
        int value = stack[top];
        top--;
        return value;

}

int peek()
{
        int value;
        if(top == -1)
        {
                printf("Underflow Condition!\n");
        }
        else
        {
                value = stack[top];
        }

        return value;
}
 
void display()
{

        for(int i = top ; i > -1 ; i--)
        {
                printf("%d\t",stack[i]);
        }
        printf("\n");
}

int main()
{
        while (1)
        {
        int option ; 
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exist\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :  
                push();
                printf("Push Success!\n");
                break;
        case 2 : 
                int value = pop();
                printf("Pop value is %d\n",value);
                break;
        case 3 : 
                int peekvalue = peek();
                printf("Peek : %d",peekvalue);
                break;
        case 4 : 
                display();
                break;
        case 5 : 
                printf("Thanks!");
                return 0;
        default:
                printf("Invalid Option!\n" );
                break;
        }
        }
        
        return 0;
}


