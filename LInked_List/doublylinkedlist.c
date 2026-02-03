#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node
{
        int data;
        struct Node *next;
        struct Node *prev;
} Node;

Node *head = NULL;
pthread_mutex_t lock;

void insert(int value)
{
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (!head)
        {
                head = newNode;
                return;
        }

        Node *temp = head;
        while (temp->next != NULL)
                temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
}

void delete(int value)
{
        if (!head)
                return;
        Node *temp = head;

        while (temp != NULL && temp->data != value)
                temp = temp->next;

        if (!temp)
                return;

        if (temp->prev)
                temp->prev->next = temp->next;
        else
                head = temp->next;

        if (temp->next)
                temp->next->prev = temp->prev;

        free(temp);
}

void display()
{
        Node *temp = head;
        if (!temp)
        {
                printf("List is empty.\n");
                return;
        }
        printf("Linked List: ");
        while (temp != NULL)
        {
                printf("%d ", temp->data);
                temp = temp->next;
        }
        printf("NULL\n");
}

void *search_forward(void *arg)
{
        int target = *(int *)arg;
        Node *temp;

        pthread_mutex_lock(&lock);
        temp = head;
        while (temp != NULL)
        {
                if (temp->data == target)
                {
                        printf("Forward Search: Found %d\n", target);
                        pthread_mutex_unlock(&lock);
                        pthread_exit(NULL);
                }
                temp = temp->next;
        }
        printf("Forward Search: %d not found\n", target);
        pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
}

void *search_backward(void *arg)
{
        int target = *(int *)arg;
        Node *temp;

        pthread_mutex_lock(&lock);
        temp = head;
        if (!temp)
        {
                pthread_mutex_unlock(&lock);
                pthread_exit(NULL);
        }

        while (temp->next != NULL)
                temp = temp->next;

        while (temp != NULL)
        {
                if (temp->data == target)
                {
                        printf("Backward Search: Found %d\n", target);
                        pthread_mutex_unlock(&lock);
                        pthread_exit(NULL);
                }
                temp = temp->prev;
        }
        printf("Backward Search: %d not found\n", target);
        pthread_mutex_unlock(&lock);
        pthread_exit(NULL);
}

int main()
{
        int choice, value, target;
        pthread_t t1, t2;
        pthread_mutex_init(&lock, NULL);

        while (1)
        {
                printf("\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        printf("Enter value to insert: ");
                        scanf("%d", &value);
                        insert(value);
                        break;
                case 2:
                        printf("Enter value to delete: ");
                        scanf("%d", &value);
                        delete(value);
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        if (!head)
                        {
                                printf("List is empty!\n");
                                break;
                        }
                        printf("Enter value to search: ");
                        scanf("%d", &target);
                        pthread_create(&t1, NULL, search_forward, &target);
                        pthread_create(&t2, NULL, search_backward, &target);
                        pthread_join(t1, NULL);
                        pthread_join(t2, NULL);
                        break;
                case 5:
                        pthread_mutex_destroy(&lock);
                        exit(0);
                default:
                        printf("Invalid choice!\n");
                }
        }

        return 0;
}
