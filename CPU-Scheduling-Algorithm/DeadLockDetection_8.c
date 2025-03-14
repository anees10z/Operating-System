#include <stdio.h>

#define P 3  // Number of processes
#define R 3  // Number of resources

int alloc[P][R], request[P][R], avail[R];

void inputData() {
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for (int i = 0; i < R; i++)
        scanf("%d", &avail[i]);
}

int detectDeadlock() {
    int finish[P] = {0}, work[R], deadlock = 0;

    for (int i = 0; i < R; i++) work[i] = avail[i];

    while (1) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int canExecute = 1;
                for (int j = 0; j < R; j++)
                    if (request[i][j] > work[j])
                        canExecute = 0;

                if (canExecute) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    for (int i = 0; i < P; i++)
        if (!finish[i]) {
            deadlock = 1;
            printf("Deadlock detected! Process P%d is in deadlock.\n", i);
        }

    if (!deadlock) printf("No Deadlock detected! System is safe.\n");
    return deadlock;
}

int main() {
    inputData();
    detectDeadlock();
    return 0;
}
