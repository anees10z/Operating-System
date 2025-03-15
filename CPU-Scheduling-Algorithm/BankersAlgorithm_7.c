#include <stdio.h>

#define P 5  // Number of processes
#define R 3  // Number of resources

int alloc[P][R], max[P][R], need[P][R], avail[R];

void inputData() {
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];  // Need = Max - Alloc
        }

    printf("Enter Available Resources:\n");
    for (int i = 0; i < R; i++)
        scanf("%d", &avail[i]);
}

int isSafe() {
    int finish[P] = {0}, safeSeq[P], work[R], count = 0;

    for (int i = 0; i < R; i++) work[i] = avail[i];

    while (count < P) {
        int found = 0;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (int j = 0; j < R; j++)
                    if (need[i][j] > work[j])
                        canAllocate = 0;
                
                if (canAllocate) {
                    for (int k = 0; k < R; k++)
                        work[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in an Unsafe State!\n");
            return 0;
        }
    }

    printf("Safe Sequence: ");
    for (int i = 0; i < P; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return 1;
}

int main() {
    inputData();
    isSafe();
    return 0;
}
