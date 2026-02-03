#ifndef TICKET_H
#define TICKET_H

#define MAX 20

typedef struct TicketBookingNode
{
    int seatNo;
    char seatType[MAX];
    struct TicketBookingNode *prev;
    struct TicketBookingNode *next;
} TicketBookingNode;

void initBooking();
void addSelectedSeat(int seatNo, char seatType[]);
void previousSeat();
void nextSeat();
void cancelSeat();
void displayAllSelectedSeat();
void displayCurrentSelectedSeat();
void displayVIPSelectedSeat();
void displayRegularSelectedSeat();
int countVIPSeat();
int countRegularSeat();
int isEmpty();
int rejectSeatNo();
void displayMenu();

#endif
