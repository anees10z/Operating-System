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