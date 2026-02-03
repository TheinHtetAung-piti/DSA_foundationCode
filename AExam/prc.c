#include <stdio.h>
#include <string.h>

#define MAX 50

/* ===== Structure Definition ===== */
struct Book
{
        int bookNo;
        char bookName[50];
        char author[50];
        int publishedYear;
};

/* ===== Function Prototypes ===== */
void readBooks(struct Book b[], int n);
void displayBooks(struct Book b[], int n);

void sortByBookNoAsc(struct Book b[], int n);
void sortByBookNameDesc(struct Book b[], int n);
void sortByAuthorAsc(struct Book b[], int n);
void sortByYearDesc(struct Book b[], int n);

void swap(struct Book *a, struct Book *b);

/* ===== Main Function ===== */
int main()
{
        struct Book books[MAX];
        int n, choice;

        printf("Enter number of books: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX)
        {
                printf("Invalid number of books.\n");
                return 0;
        }

        readBooks(books, n);

        do
        {
                printf("\n===== MENU =====\n");
                printf("1. Display books before sorting\n");
                printf("2. Sort by Book No (Ascending)\n");
                printf("3. Sort by Book Name (Descending)\n");
                printf("4. Sort by Author (Ascending)\n");
                printf("5. Sort by Published Year (Descending)\n");
                printf("6. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                        displayBooks(books, n);
                        break;

                case 2:
                        sortByBookNoAsc(books, n);
                        printf("Sorted by Book No (Ascending)\n");
                        displayBooks(books, n);
                        break;

                case 3:
                        sortByBookNameDesc(books, n);
                        printf("Sorted by Book Name (Descending)\n");
                        displayBooks(books, n);
                        break;

                case 4:
                        sortByAuthorAsc(books, n);
                        printf("Sorted by Author (Ascending)\n");
                        displayBooks(books, n);
                        break;

                case 5:
                        sortByYearDesc(books, n);
                        printf("Sorted by Published Year (Descending)\n");
                        displayBooks(books, n);
                        break;

                case 6:
                        printf("Exiting program...\n");
                        break;

                default:
                        printf("Invalid choice\n");
                }
        } while (choice != 6);

        return 0;
}

/* ===== Read Book Records ===== */
void readBooks(struct Book b[], int n)
{
        for (int i = 0; i < n; i++)
        {
                printf("\nEnter details of Book %d\n", i + 1);

                do
                {
                        printf("Book No: ");
                        scanf("%d", &b[i].bookNo);
                        if (b[i].bookNo <= 0)
                                printf("Book number must be positive.\n");
                } while (b[i].bookNo <= 0);

                getchar(); // clear buffer

                do
                {
                        printf("Book Name: ");
                        gets(b[i].bookName);
                        if (strlen(b[i].bookName) == 0)
                                printf("Book Name cannot be empty.\n");
                } while (strlen(b[i].bookName) == 0);

                do
                {
                        printf("Author: ");
                        gets(b[i].author);
                        if (strlen(b[i].author) == 0)
                                printf("Author cannot be empty.\n");
                } while (strlen(b[i].author) == 0);

                printf("Published Year: ");
                scanf("%d", &b[i].publishedYear);
        }
}

/* ===== Display Books ===== */
void displayBooks(struct Book b[], int n)
{
        printf("\n%-10s %-20s %-20s %-10s\n",
               "BookNo", "Book Name", "Author", "Year");

        for (int i = 0; i < n; i++)
        {
                printf("%-10d %-20s %-20s %-10d\n",
                       b[i].bookNo, b[i].bookName,
                       b[i].author, b[i].publishedYear);
        }
}

/* ===== Bubble Sort Functions ===== */

// Book No Ascending
void sortByBookNoAsc(struct Book b[], int n)
{
        for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                        if (b[j].bookNo > b[j + 1].bookNo)
                                swap(&b[j], &b[j + 1]);
}

// Book Name Descending
void sortByBookNameDesc(struct Book b[], int n)
{
        for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                        if (strcmp(b[j].bookName, b[j + 1].bookName) < 0)
                                swap(&b[j], &b[j + 1]);
}

// Author Ascending
void sortByAuthorAsc(struct Book b[], int n)
{
        for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                        if (strcmp(b[j].author, b[j + 1].author) > 0)
                                swap(&b[j], &b[j + 1]);
}

// Published Year Descending
void sortByYearDesc(struct Book b[], int n)
{
        for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                        if (b[j].publishedYear < b[j + 1].publishedYear)
                                swap(&b[j], &b[j + 1]);
}

/* ===== Swap Function ===== */
void swap(struct Book *a, struct Book *b)
{
        struct Book temp = *a;
        *a = *b;
        *b = temp;
}
