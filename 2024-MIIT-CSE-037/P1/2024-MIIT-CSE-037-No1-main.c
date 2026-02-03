#include <stdio.h>
#include "2024-MIIT-CSE-037-No1.h"
#include "2024-MIIT-CSE-037-No1.c"
int main()
{
        Patient_Queue q;
        CreateQueue(&q);
Opt:
        printf("\n-----Hospital Patient Queue System-----\n");
        printf("1.Register Patient(Enqueue)\n");
        printf("2.Treate Patient(Dequeue)\n");
        printf("3.View Next Patient\n");
        printf("4.Diaplay Waiting Paitents\n");
        printf("5.Count Emergency Patients\n");
        printf("6.Search Patient\n");
        printf("7.Count Total Patients\n");
        printf("8.Check Queue Status\n");
        printf("9.Exist\n");
        printf("Enter your choice : ");
        int opt;
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
                printf("Enter Patient ID to register : ");
                int id_Reg;
                scanf("%d", &id_Reg);
                RegisterPatient(&q, id_Reg);
                break;
        case 2:
                int id_Treat = TreatPatient(&q);
                if (id_Treat == -1)
                {
                        break;
                }
                printf("Patient %d Treated!\n", id_Treat);
                break;
        case 3:
                int id_View = ViewNextPatient(&q);
                if (id_View == -1)
                {
                        break;
                }
                printf("Next Patient : %d", id_View);
                break;
        case 4:
                DisplayPatient(&q);
                break;
        case 5:
                int emg_Count = CountEmergency(&q);
                if (emg_Count == -1)
                {
                        break;
                }
                printf("%d Emergency Patients!\n");
                break;
        case 6:
                int id_Search;
                printf("Enter ID to Search : ");
                scanf("%d", &id_Search);
                SearchPatient(&q, id_Search);
                break;
        case 7:
                int count = CountPatient(&q);
                if (count == -1)
                {
                        break;
                }
                printf("%d Patients Waiting!\n", count);
                break;
        case 8:
                QueueStatus(&q);
                break;

        case 9:
                printf("Thanks For using!\n");
                return 0;
                break;
        default:
                printf("Invalid Option!\n");
                break;
        }

        goto Opt;
        printf("\n");
        return 0;
}