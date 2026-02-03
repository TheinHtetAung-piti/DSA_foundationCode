#include <stdio.h>
#include "list_adh.h"

void initLIst(List *l)
{
    l->count = 0;
}

int isEmpty(List *l)
{
    return (l->count == 0);
}

int isFull(List *l)
{
    return (l->count == MAX);
}

int size(List *l)
{
    return l->count;
}

int get(List *l, int pos, ElementType *item)
{
    if (pos < 0 || pos >= l->count)
        return 0;

    *item = l->data[pos];
    return 1;
}

int insert(List *l, int pos, ElementType item)
{
    if (isFull(l)) return 0;
    if (pos < 0 || pos > l->count) return 0;

    for (int i = l->count; i > pos; i--)
    {
        l->data[i] = l->data[i - 1];
    }

    l->data[pos] = item;
    l->count++;
    return 1;
}

int removeItem(List *l, ElementType item)
{
    int pos = -1;
    for (int i = 0; i < l->count; i++)
    {
        if (l->data[i] == item)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1) return 0;

    return removeAt(l, pos);
}

int removeAt(List *l, int pos)
{
    if (pos < 0 || pos >= l->count) return 0;

    for (int i = pos; i < l->count - 1; i++)
    {
        l->data[i] = l->data[i + 1];
    }
    l->count--;
    return 1;
}

int replace(List *l, int pos, ElementType newItem)
{
    if (pos < 0 || pos >= l->count) return 0;

    l->data[pos] = newItem;
    return 1;
}

void display(List *l)
{
    if (isEmpty(l))
    {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    for (int i = 0; i < l->count; i++)
    {
        printf("%d ", l->data[i]);
    }
    printf("\n");
}
