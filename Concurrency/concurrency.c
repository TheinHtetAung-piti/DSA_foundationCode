#include <stdio.h>
#include <pthread.h>

// Function for thread
void* task(void* arg)
{
    char* name = (char*)arg;
    for(int i = 1; i <= 5; i++)
    {
        printf("%s: %d\n", name, i);
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_create(&t1, NULL, task, "testing 1");
    pthread_create(&t2, NULL, task, "tesitng 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("All threads finished\n");
    return 0;
}
