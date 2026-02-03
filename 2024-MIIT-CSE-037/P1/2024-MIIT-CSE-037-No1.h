#ifndef PATIENT_H
#define PATIENT_H

#define MAX 100
typedef struct 
{
        int Patients[MAX];
        int front;
        int rear;
}Patient_Queue;

void CreateQueue(Patient_Queue *q);
int isEmpty(Patient_Queue *q);
int isFull(Patient_Queue *q);
void RegisterPatient(Patient_Queue *q,int id_Patient);
int TreatPatient(Patient_Queue *q);
int ViewNextPatient(Patient_Queue *q);
void DisplayPatient(Patient_Queue *q);
int CountEmergency(Patient_Queue *q);
int SearchPatient(Patient_Queue *q,int id_Patient);
int CountPatient(Patient_Queue *q);

#endif