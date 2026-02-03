#include <stdio.h>
#include "2024-MIIT-CSE-037-No2.h"
#include "2024-MIIT-CSE-037-No2.c"

int main()
{
    int choice, seatNo;
    char type[20];

    initBooking();
    displayMenu();

    while (1)
    {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Seat No: ");
            scanf("%d", &seatNo);
            printf("Enter Seat Type (VIP/Regular): ");
            scanf("%s", type);
            addSelectedSeat(seatNo, type);
            break;

        case 2:
            previousSeat();
            break;

        case 3:
            nextSeat();
            break;

        case 4:
            cancelSeat();
            break;

        case 5:
            displayAllSelectedSeat();
            break;

        case 6:
            displayCurrentSelectedSeat();
            break;

        case 7:
            displayVIPSelectedSeat();
            break;

        case 8:
            displayRegularSelectedSeat();
            break;

        case 9:
            printf("VIP Seats  : %d\n", countVIPSeat());
            break;

        case 10:
            printf("Reglar Seats: %d\n", countRegularSeat());
            break;

        case 11:
            rejectSeatNo();
            break;
        case 12:
            displayMenu();
        case 13:
        printf("Thanks!\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
