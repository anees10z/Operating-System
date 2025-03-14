#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define SHM_SIZE 1024  // Shared memory size

int main() {
    int shmid;
    char *shm;

    // Step 1: Create shared memory
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to create shared memory!\n");
        return 1;
    }

    // Step 2: Fork a child process
    pid_t pid = fork();

    if (pid == 0) {  // Child Process
        sleep(1);  // Ensure parent writes first
        shm = (char *)shmat(shmid, NULL, 0);
        printf("Child reads: %s\n", shm);

        // Child sends response to parent
        strcpy(shm, "Hello Parent! How are you?");
        printf("Child writes: %s\n", shm);
        sleep(1);

        // Child reads second message from parent
        printf("Child reads again: %s\n", shm);

        shmdt(shm);
    } 
    else {  // Parent Process
        shm = (char *)shmat(shmid, NULL, 0);

        // Parent sends first message to child
        strcpy(shm, "Hello Child! How are you?");
        printf("Parent writes: %s\n", shm);

        wait(NULL); // Wait for child to respond

        // Parent reads child's response
        printf("Parent reads: %s\n", shm);

        // Parent sends another message
        strcpy(shm, "I'm doing great! Take care.");
        printf("Parent writes: %s\n", shm);

        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL); // Remove shared memory
    }
    return 0;
}
