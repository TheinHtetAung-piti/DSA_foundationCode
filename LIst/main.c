#include <stdio.h>
#include "list_adh.h"
#include "list_adt.c"

int main()
{
    List list;
    ElementType item;

    initLIst(&list);

    insert(&list, 0, 10);
    insert(&list, 1, 20);
    insert(&list, 2, 30);
    insert(&list, 1, 15);

    display(&list);

    printf("Size = %d\n", size(&list));

    if (get(&list, 2, &item))
        printf("Item at pos 2: %d\n", item);

    replace(&list, 1, 99);
    display(&list);

    removeItem(&list, 30);
    display(&list);

    removeAt(&list, 0);
    display(&list);

    return 0;
}
