#include <stdio.h>
#define MAX 10

typedef struct
{
        int mpq[MAX];
        int size;
} MQ;

int deletion(MQ *q)
{
        if(q->size == 0 )
        {
                printf("Underflow!\n");
                return -1;
        }
        int delvalue = q->mpq[0];
        for(int i = 0 ; i < q->size ; i++)
        {
                q->mpq[i] = q->mpq[i+1];
                
        }
        q->size--;
        return delvalue;
}
void insert(MQ *q, int value)
{
        if (q->size == MAX)
        {
                printf("Overflow!\n");
                return;
        }
        printf("Insertiong is loading!\n");
        int i = 0;
        for (i = q->size - 1; i >= 0 && q->mpq[i] < value; i--)
        {
                q->mpq[i + 1] = q->mpq[i];
        }
        q->mpq[i + 1] = value;
        q->size++;
        printf("Insertion success!\n");
}
int peek(MQ *q)
{
        if(q->size == 0)
        {
                printf("Underflow!\n");
                return -1;
        }
        int delvalue = q->mpq[0];

}

void display(MQ *q)
{
        for(int i = 0 ; i < q->size ; i++)
        {
                printf("%3d",q->mpq[i]);
        }
        printf("\n");
}
int main()
{
        MQ q;
        q.size = 2;
        q.mpq[0] = 10;
        q.mpq[1] = 8;
        int val;

        // insertion
        printf("Enter value : ");
        scanf("%d",&val);
        insert(&q, val);
        display(&q);

        int delval = deletion(&q);
        printf("Del value is : %d",delval);
        return 0;
}