#ifndef CHAR_LIST_h
#define CHAR_LIST_h
#define MAX 10
typedef char Datatype;

typedef struct 
{
        char list[MAX];
        int size;
} LIST;

 extern LIST char_list;


void insert(LIST *l,int pos,char ch);

void del(LIST *l,int pos);

void display(LIST *l);

int countVowels(LIST *l);

#endif 