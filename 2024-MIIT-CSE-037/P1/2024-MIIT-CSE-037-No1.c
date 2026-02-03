#include <stdio.h>
#include "2024-MIIT-CSE-037-No1.h"

void CreateQueue(Patient_Queue *q)
{
        q->front = -1;
        q->rear = -1;
}
int isEmpty(Patient_Queue *q)
{
        return q->front == -1;
}
int isFull(Patient_Queue *q)
{
        return q->rear == MAX - 1;
}
void RegisterPatient(Patient_Queue *q, int id_Patient)
{
        if (isFull(q))
        {
                printf("Full Patients!\n");
                return;
        }

        if (isEmpty(q))
                q->front = 0;

        q->Patients[++q->rear] = id_Patient;
        printf("Patient Register Success!\n");
        printf("Register Patient %d", id_Patient);
}
int TreatPatient(Patient_Queue *q)
{
        if (isEmpty(q))
        {
                printf("No Patients!\n");
                return -1;
        }

        int val = q->Patients[q->front++];

        if (q->front > q->rear)
        {
                q->front = q->rear = -1;
        }

        return val;
}

int ViewNextPatient(Patient_Queue *q)
{
        if (isEmpty(q))
        {
                printf("No Patients!\n");
                return -1;
        }

        int val = q->Patients[q->front];

        if (q->front > q->rear)
        {
                q->front = q->rear = -1;
        }

        return val;
}
void DisplayPatient(Patient_Queue *q)
{
        if (isEmpty(q))
        {
                printf("No Patients!\n");
                return;
        }

        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++)
                printf("%d ", q->Patients[i]);
        printf("\n");
}
int CountEmergency(Patient_Queue *q)
{
        if (isEmpty(q))
        {
                printf("No Patients!\n");
                return -1;
        }
        int cnt = 0;

        for (int i = q->front; i <= q->rear; i++)
        {
                if (q->Patients[i] % 2 == 0)
                {
                        cnt++;
                }
        }
        return cnt;
}
int SearchPatient(Patient_Queue *q, int id_Patient)
{
        if (isEmpty(q))
        {
                printf("No Patients!\n");
                return -1;
        }
        int cnt = 0;

        for (int i = q->front; i <= q->rear; i++)
        {
                if (q->Patients[i] == id_Patient)
                {
                        printf("Found in the queue!\n");
                        return -1;
                }
        }

        printf("Not Found!\n");
}
int CountPatient(Patient_Queue *q)
{
        if (isEmpty(q))
        {
                printf("No Patients!\n");
                return -1;
        }
        int cnt = 0;

        for (int i = q->front; i <= q->rear; i++)
        {
                cnt++;
        }
        return cnt;
}

void QueueStatus(Patient_Queue *q)
{
        if (isEmpty(q))
        {
                printf("Queue is Empty!\n");
        }
        if (isFull(q))
        {
                printf("Queue is Full!\n");
        }
}
