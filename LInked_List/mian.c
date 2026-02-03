#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
        int Data;
        struct Node *next;
};

int main()
{
        struct Node *head = NULL, *newNode, *ptr;
        int n, num;

        printf("Enter nmber of nodes : ");
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
        {
                printf("Enter the data : ");
                scanf("%d", &num);

                newNode = malloc(sizeof(struct Node));
                newNode->Data = num;
                newNode->next = NULL;

                if (head == NULL)
                {
                        head = newNode;
                        continue;
                }
                ptr = head;
                while (ptr->next != NULL)
                {
                        ptr = ptr->next;
                }
                ptr->next = newNode;
        }

        printf("Linked List : ");
        ptr = head;
        while (ptr != NULL)
        {
                printf("%d -> ", ptr->Data);
                ptr = ptr->next;
        }
        printf("NULL\n");

        int searchNum, searchPos = 1, flag = 0;

        printf("Enter Element to search : ");
        scanf("%d", &searchNum);

        ptr = head;
        while (ptr != NULL)
        {
                if (ptr->Data == searchNum)
                {
                        printf("Element found at position : %d !", searchPos);
                        return 0;
                }
                searchPos++;
                ptr = ptr->next;
        }
        printf("Element Not Found!");

        return 0;
}
