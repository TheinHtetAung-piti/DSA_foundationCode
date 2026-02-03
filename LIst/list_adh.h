#ifndef LIST_ADT_H
#define LIST_ADT_H
#define MAX 100

typedef int ElementType;

typedef struct 
{
        ElementType data[MAX];
        int count;
} List;

void initLIst(List *l);
int isEmpty(List *l);
int isFull(List *l);
int size(List *l);
int get(List *l,int pos , ElementType *item);
int insert(List *l , int pos , ElementType item);
int removeItem(List *l, ElementType item);
int removeAt(List *l, int pos);
int replace(List *l , int pos, ElementType newItem);
void display(List *l);

#endif