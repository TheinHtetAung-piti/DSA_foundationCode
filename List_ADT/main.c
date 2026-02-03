#include<stdio.h>
#include "char_list.h"
#include "char_list.c"

int main()
{
        LIST char_list = {.list = {0}, .size = 0};
        int option;
        while(1)
        {       int option ;
                printf("\n1.insert\n");
                printf("2.delete\n");
                printf("3.display\n");
                printf("4.count vowels\n");
                printf("5.exist\n");
                printf("\nEnter option : ");
                scanf("%d",&option);

                switch (option)
                {
                case 1:
                        int pos ;
                        char ch;
                        printf("Enter positon to inesrt : ");
                        scanf("%d",&pos);
                        printf("Enter new char : ");
                        scanf(" %c", &ch);
                        insert(&char_list,pos,ch);
                        break;
                case 2:
                        int delpos ;
                        printf("Enter positon to delete : ");
                        scanf("%d",&delpos);
                        del(&char_list,delpos);
                        break;
                case 3:
                        display(&char_list);
                        break;
                case 4:
                        int count = countVowels(&char_list);
                        printf("There are %d vowels !",count);
                        break;
                case 5:
                        printf("Thanks!\n");
                        return 0;
                default: 
                        printf("Invalid Option!\n");
                        break;
                }
        }
        return 0;
}