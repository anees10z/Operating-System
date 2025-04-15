#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
// to run this program in terminal add -lpthread like shown below
// gcc semaphore.c -lpthread
// ./a.out
#define Num_threads 5

sem_t semaphore;

void *accessResource(void *arg)
{
    printf("Thread %d is waiting to access the resource \n", *(int *)arg);
    sem_wait(&semaphore);
    printf("Thread %d is accesing resource \n", *(int *)arg);
    sleep(2);
    printf("Thread %d has finished accessing the resource\n", *(int *)arg);
    sem_post(&semaphore);
    free(arg);
    return NULL;
}

int main()
{
    sem_init(&semaphore, 0, 3);
    pthread_t threads[Num_threads];

    for (int i = 0; i < Num_threads; i++)
    {
        int *threadId = malloc(sizeof(int));
        *threadId = i;
        pthread_create(&threads[i], NULL, accessResource, threadId);
    }
    for (int i = 0; i < Num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}

/*
#include <stdio.h>
#include <unistd.h> 

int main()
{
    int semaphore = 2;
    int thread = 5;
    
    printf("Only 2 thread access resources at a time \n");
    
    for(int i = 1; i<=thread; ++i)
    {
        printf("Thread %d is waiting for accessing resource\n", i);
        if(semaphore > 0)
        {
            semaphore--;
            printf("Thread %d is accessing resource\n", i);
            sleep(2);
            semaphore++;
            printf("Thread %d is finished accessing resource\n", i);
        }
        else
        {
            printf("Resouces are full\n");
            i--;
        }
        sleep(1);
    }
    printf("\nAll threads are finished\n");
    
    return 0;
}
*/
