#include <stdio.h>
#include <stdlib.h>

#define QMAX 5

/* ================= LINKED LIST ================= */

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Linked List functions */
Node* createNode(int value);
void insertAtBeginning(Node **head, int value);
void insertAtEnd(Node **head, int value);
void deleteByValue(Node **head, int value);
void displayList(Node *head);

/* Sorting methods */
void bubbleSort(Node *head);
void selectionSort(Node *head);
void insertionSort(Node **head);

/* ================= QUEUE ================= */

typedef struct {
    int data[QMAX];
    int front;
    int rear;
} Queue;

void createQueue(Queue *q);
int isQueueEmpty(Queue *q);
int isQueueFull(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void displayQueue(Queue *q);

/* ================= LINKED LIST CODE ================= */

Node* createNode(int value)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;
    return n;
}

void insertAtBeginning(Node **head, int value)
{
    Node *n = createNode(value);
    n->next = *head;
    *head = n;
}

void insertAtEnd(Node **head, int value)
{
    Node *n = createNode(value);
    if (*head == NULL) {
        *head = n;
        return;
    }

    Node *t = *head;
    while (t->next != NULL)
        t = t->next;

    t->next = n;
}

void deleteByValue(Node **head, int value)
{
    Node *t = *head, *p = NULL;

    while (t != NULL) {
        if (t->data == value) {
            if (p == NULL)
                *head = t->next;
            else
                p->next = t->next;

            free(t);
            printf("Deleted successfully\n");
            return;
        }
        p = t;
        t = t->next;
    }
    printf("Value not found\n");
}

void displayList(Node *head)
{
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* ================= SORTING ================= */

void bubbleSort(Node *head)
{
    int swapped;
    Node *p;
    Node *last = NULL;

    if (head == NULL) return;

    do {
        swapped = 0;
        p = head;

        while (p->next != last) {
            if (p->data > p->next->data) {
                int t = p->data;
                p->data = p->next->data;
                p->next->data = t;
                swapped = 1;
            }
            p = p->next;
        }
        last = p;
    } while (swapped);

    printf("Bubble sort done\n");
}

void selectionSort(Node *head)
{
    Node *i, *j, *min;

    for (i = head; i != NULL; i = i->next) {
        min = i;
        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < min->data)
                min = j;
        }
        if (min != i) {
            int t = i->data;
            i->data = min->data;
            min->data = t;
        }
    }
    printf("Selection sort done\n");
}

void insertionSort(Node **head)
{
    Node *sorted = NULL;
    Node *curr = *head;

    while (curr != NULL) {
        Node *next = curr->next;

        if (sorted == NULL || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Node *t = sorted;
            while (t->next != NULL && t->next->data < curr->data)
                t = t->next;

            curr->next = t->next;
            t->next = curr;
        }
        curr = next;
    }
    *head = sorted;
    printf("Insertion sort done\n");
}

/* ================= QUEUE CODE ================= */

void createQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q)
{
    return (q->front == -1);
}

int isQueueFull(Queue *q)
{
    return (q->rear == QMAX - 1);
}

void enqueue(Queue *q, int value)
{
    if (isQueueFull(q)) {
        printf("Queue full\n");
        return;
    }

    if (isQueueEmpty(q))
        q->front = 0;

    q->rear++;
    q->data[q->rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q)) {
        printf("Queue empty\n");
        return -1;
    }

    int v = q->data[q->front];
    q->front++;

    if (q->front > q->rear)
        q->front = q->rear = -1;

    return v;
}

void displayQueue(Queue *q)
{
    if (isQueueEmpty(q)) {
        printf("Queue empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->data[i]);
    printf("\n");
}

/* ================= MAIN MENU ================= */

int main()
{
    Node *head = NULL;
    Queue q;
    int choice, value;

    createQueue(&q);

    do {
        printf("\n--- LIST & QUEUE (ONE FILE) ---\n");
        printf("1  Insert List Begin\n");
        printf("2  Insert List End\n");
        printf("3  Delete List Value\n");
        printf("4  Display List\n");
        printf("5  Bubble Sort\n");
        printf("6  Selection Sort\n");
        printf("7  Insertion Sort\n");
        printf("8  Enqueue\n");
        printf("9  Dequeue\n");
        printf("10 Display Queue\n");
        printf("0  Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;
        case 2:
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;
        case 3:
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            bubbleSort(head);
            break;
        case 6:
            selectionSort(head);
            break;
        case 7:
            insertionSort(&head);
            break;
        case 8:
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 9:
            value = dequeue(&q);
            if (value != -1)
                printf("Deleted %d\n", value);
            break;
        case 10:
            displayQueue(&q);
            break;
        case 0:
            printf("Exit\n");
            break;
        default:
            printf("Invalid\n");
        }
    } while (choice != 0);

    return 0;
}
