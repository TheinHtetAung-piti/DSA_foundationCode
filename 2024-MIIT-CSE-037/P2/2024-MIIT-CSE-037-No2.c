#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2024-MIIT-CSE-037-No2.h"

static TicketBookingNode *head = NULL;
static TicketBookingNode *current = NULL;

static TicketBookingNode *createNode(int seatNo, char seatType[])
{
    TicketBookingNode *node = (TicketBookingNode *)malloc(sizeof(TicketBookingNode));
    node->seatNo = seatNo;
    strcpy(node->seatType, seatType);
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void initBooking()
{
    head = NULL;
    current = NULL;
}

int isEmpty()
{
    return head == NULL;
}

void addSelectedSeat(int seatNo, char seatType[])
{
    TicketBookingNode *newNode = createNode(seatNo, seatType);

    if (head == NULL)
    {
        head = current = newNode;
        return;
    }

    TicketBookingNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    current = newNode;
}

void previousSeat()
{
    if (current == NULL || current->prev == NULL)
    {
        printf("No previous seat!\n");
        return;
    }
    current = current->prev;
    displayCurrentSelectedSeat();
}

void nextSeat()
{
    if (current == NULL || current->next == NULL)
    {
        printf("No next seat!\n");
        return;
    }
    current = current->next;
    displayCurrentSelectedSeat();
}

void cancelSeat()
{
    if (current == NULL)
    {
        printf("No seat selected!\n");
        return;
    }

    TicketBookingNode *temp = current;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    current = temp->next != NULL ? temp->next : temp->prev;
    free(temp);
}

void displayCurrentSelectedSeat()
{
    if (current == NULL)
    {
        printf("No seat selected!\n");
        return;
    }
    printf("Seat No : %d  Type : %s\n", current->seatNo, current->seatType);
}
void displayAllSelectedSeat()
{
    if (isEmpty())
    {
        printf("Seat list empty!\n");
        return;
    }

    TicketBookingNode *temp = head;
    while (temp != NULL)
    {
        printf("Seat No : %d | Type : %s\n", temp->seatNo, temp->seatType);
        temp = temp->next;
    }
}
void displayVIPSelectedSeat()
{
    TicketBookingNode *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->seatType, "VIP") == 0)
            printf("Seat No : %d | VIP\n", temp->seatNo);
        temp = temp->next;
    }
}
void displayRegularSelectedSeat()
{
    TicketBookingNode *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->seatType, "Regular") == 0)
            printf("Seat No : %d | Regular\n", temp->seatNo);
        temp = temp->next;
    }
}
int countVIPSeat()
{
    int count = 0;
    TicketBookingNode *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->seatType, "VIP") == 0)
            count++;
        temp = temp->next;
    }
    return count;
}
int countRegularSeat()
{
    int count = 0;
    TicketBookingNode *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->seatType, "Regular") == 0)
            count++;
        temp = temp->next;
    }
    return count;
}
int rejectSeatNo()
{
    
}
void displayMenu()
{
    printf("\n1. Add Seat\n");
    printf("2. Previous Seat\n");
    printf("3. Next Seat\n");
    printf("4. Cancel Seat\n");
    printf("5. Display All Seats\n");
    printf("6. Display Current Seat\n");
    printf("7. Display VIP Seats\n");
    printf("8. Display Regular Seats\n");
    printf("9. Count VIP Seats\n");
    printf("10. Count Regular Seats\n");
    printf("11. Exit\n");
}
