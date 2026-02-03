#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 10

int arr[SIZE] = {5, 12, 8, 20, 7, 15, 3, 9, 1, 18};
int target = 7;

volatile int found = 0;          // shared flag
pthread_t forwardThread, backwardThread;

// Forward search thread
void* search_forward(void* arg)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (found) pthread_exit(NULL);

        printf("Forward checking index %d\n", i);
        if (arr[i] == target)
        {
            printf("Found %d at index %d (Forward)\n", target, i);
            found = 1;
            pthread_cancel(backwardThread);
            pthread_exit(NULL);
        }
        // sleep(1);
    }
    return NULL;
}

// Backward search thread
void* search_backward(void* arg)
{
    for (int i = SIZE - 1; i >= 0; i--)
    {
        if (found) pthread_exit(NULL);

        printf("Backward checking index %d\n", i);
        if (arr[i] == target)
        {
            printf("Found %d at index %d (Backward)\n", target, i);
            found = 1;
            pthread_cancel(forwardThread);
            pthread_exit(NULL);
        }
        // sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_create(&forwardThread, NULL, search_forward, NULL);
    pthread_create(&backwardThread, NULL, search_backward, NULL);

    pthread_join(forwardThread, NULL);
    pthread_join(backwardThread, NULL);

    if (!found)
        printf("Item not found\n");
    else
        printf("Search stopped after finding item\n");

    return 0;
}
