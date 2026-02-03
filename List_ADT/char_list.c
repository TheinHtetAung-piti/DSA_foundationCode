#include <stdio.h>
#include <ctype.h>
#include "char_list.h"
#define MAX 10


void insert(LIST *l,int pos,char ch)
{
        
        if(l->size == MAX)
        {
                printf("Full of List!\n");
        }
        else
        {
                if(pos < 0 || pos > MAX)
                {
                        printf("Invalid pos!\n");
                        goto end;
                }
                for( int i = l->size - 1 ; i > pos ; i--)
                {
                        l->list[i+1] = l->list[i];
                }
                l->list[pos] = ch;
                l->size++;
                printf("Success To Insert!\n");
                end:
                printf("\n");
        }
}

void del(LIST *l, int pos)
{
    if(l->size == 0)
    {
        printf("Empty List!\n");
        return;
    }

    if(pos < 0 || pos >= l->size)
    {
        printf("Invalid position!\n");
        return;
    }

    for(int i = pos; i < l->size ; i++)
    {
        l->list[i] = l->list[i + 1];
    }

    l->size--;
    printf("Successfully deleted!\n\n");
}


void display(LIST *l)
{
        printf("List : ");
        for(int i = 0 ; i < l->size ; i++)
        {
                printf("%c\t",l->list[i]);
        }
        printf("\n");
}

int countVowels(LIST *l)
{
        int count = 0 ; 
        for(int i = 0 ; i < l->size ; i++)
        {
                char check = tolower(l->list[i]);
                if( check == 'a' || check == 'e' || check == 'i'
                || check == 'o' || check == 'u')
                {
                        count++;
                }
        }

        return count;
}
