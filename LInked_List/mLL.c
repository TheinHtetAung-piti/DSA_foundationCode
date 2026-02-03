#include <stdio.h>
#include <stdlib.h>

struct node
{
        int data;
        struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

int main()
{
        int option;
        do
        {
                printf("\n\n *****MAIN MENU*****");
                printf("\n 1: Create a list");
                printf("\n 2: Display the list");
                printf("\n 3: Delete a node from the beginning");
                printf("\n 4: Delete a node from the end");
                printf("\n 5: Delete a given node");
                printf("\n 6: Delete a node after a given node");
                printf("\n 7: Delete the entire list");
                printf("\n 8: EXIT");
                printf("\n\n Enter your option : ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                        start = create_ll(start);
                        printf("\n LINKED LIST CREATED");
                        break;
                case 2:
                        start = display(start);
                        break;
                case 3:
                        start = delete_beg(start);
                        break;
                case 4:
                        start = delete_end(start);
                        break;
                case 5:
                        start = delete_node(start);
                        break;
                case 6:
                        start = delete_after(start);
                        break;
                case 7:
                        start = delete_list(start);
                        printf("\n LINKED LIST DELETED");
                        break;
                case 8:
                        printf("Thanks!\n");
                        return 0;
                default:
                        printf("Invalid Option!\n");
                        break;
                }
        } while (option != 8);
        return 0;
}

struct node *create_ll(struct node *start)
{
        struct node *new_node, *ptr;
        int num;
        printf("\n Enter-1 to end");
        printf("\n Enter the data : ");
        scanf("%d", &num);
        while (num != -1)
        {
                new_node = (struct node *)malloc(sizeof(struct node));
                new_node->data = num;
                if (start == NULL)
                {
                        new_node->next = NULL;
                        start = new_node;
                }
                else
                {
                        ptr = start;
                        while (ptr->next != NULL)
                                ptr = ptr->next;
                        ptr->next = new_node;
                        new_node->next = NULL;
                }
                printf("\n Enter the data : ");
                scanf("%d", &num);
        }
        return start;
}

struct node *display(struct node *start)
{
        struct node *ptr;
        ptr = start;
        if (ptr == NULL)
        {
                printf("List is empty.\n");
        }
        else
        {
                while (ptr != NULL)
                {
                        printf("\t %d", ptr->data);
                        ptr = ptr->next;
                }
        }
        return start;
}

struct node *delete_beg(struct node *start)
{
        struct node *ptr;
        ptr = start;
        if (ptr == NULL)
        {
                printf("Linked List is empty.\n");
        }
        else
        {
                start = start->next;
                free(ptr);
        }
        return start;
}

struct node *delete_end(struct node *start)
{
        struct node *ptr, *preptr;
        if (start == NULL)
        {
                printf("Linked List is empty.\n");
        }
        else if (start->next == NULL)
        {
                free(start);
                start = NULL;
        }
        else
        {
                ptr = start;
                while (ptr->next != NULL)
                {
                        preptr = ptr;
                        ptr = ptr->next;
                }
                preptr->next = NULL;
                free(ptr);
        }
        return start;
}

struct node *delete_node(struct node *start)
{
        struct node *ptr, *preptr;
        int val;

        if (start == NULL)
        {
                printf("Linked List is empty.\n");
                return start;
        }

        printf("\n Enter the value of the node which has to be deleted : ");
        scanf("%d", &val);

        ptr = start;

        if (ptr->data == val)
        {
                start = delete_beg(start);
                return start;
        }

        while (ptr != NULL && ptr->data != val)
        {
                preptr = ptr;
                ptr = ptr->next;
        }

        if (ptr != NULL)
        {
                preptr->next = ptr->next;
                free(ptr);
        }
        else
        {
                printf("\nValue %d not found in the list.\n", val);
        }

        return start;
}

struct node *delete_after(struct node *start)
{
        struct node *ptr;
        int val;

        if (start == NULL)
        {
                printf("Linked List is empty.\n");
                return start;
        }

        printf("\n Enter the value after which the node has to be deleted : ");
        scanf("%d", &val);

        ptr = start;

        while (ptr != NULL && ptr->data != val)
                ptr = ptr->next;

        if (ptr != NULL && ptr->next != NULL)
        {
                struct node *temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
        }
        else if (ptr == NULL)
        {
                printf("\nValue %d not found in the list.\n", val);
        }
        else
        {
                printf("\nNo node exists after %d to delete.\n", val);
        }

        return start;
}

struct node *delete_list(struct node *start)
{
        struct node *ptr;
        if (start != NULL)
        {
                ptr = start;
                while (ptr != NULL)
                {
                        printf("\n %d is to be deleted next", ptr->data);
                        start = delete_beg(start);
                        ptr = start;
                }
        }
        return start;
}
