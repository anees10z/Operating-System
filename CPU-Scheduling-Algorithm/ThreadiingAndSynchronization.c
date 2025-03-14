#include <stdio.h>
#include <pthread.h>

int counter = 0;  // Shared resource
pthread_mutex_t lock;  // Mutex lock

void* increment(void* arg) {
    pthread_mutex_lock(&lock);  // Lock critical section
    counter++;
    printf("Thread %d: Counter = %d\n", *(int*)arg, counter);
    pthread_mutex_unlock(&lock);  // Unlock after execution
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_mutex_init(&lock, NULL); // Initialize mutex

    pthread_create(&t1, NULL, increment, &id1);
    pthread_create(&t2, NULL, increment, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock); // Destroy mutex

    printf("Final Counter: %d\n", counter);
    return 0;
}
