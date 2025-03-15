#include <stdio.h>
#define MAX 50 // Maximum number of blocks

int f[MAX], index[MAX]; // Disk block status and index table

int main() {
    int n, ind, i, count, c;
    
    // Initialize all blocks as free
    for (i = 0; i < MAX; i++) 
        f[i] = 0;

    while (1) {
        printf("Enter index block: ");
        scanf("%d", &ind);

        if (ind < 0 || ind >= MAX) {
            printf("Error: Invalid index block! Try again.\n");
            continue;
        }

        if (f[ind]) {
            printf("Index block already allocated! Try another.\n");
            continue;
        }

        printf("Enter number of blocks needed: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {
            printf("Error: Invalid number of blocks! Try again.\n");
            continue;
        }

        printf("Enter block numbers: ");
        count = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);

            // Check if block is within range and not allocated
            if (index[i] >= 0 && index[i] < MAX && !f[index[i]]) 
                count++;
        }

        if (count == n) { // All blocks are free
            f[ind] = 1;
            for (i = 0; i < n; i++) 
                f[index[i]] = 1;

            printf("Allocated\nFile Indexed\n");
            for (i = 0; i < n; i++)
                printf("%d -> %d\n", ind, index[i]);
        } else {
            printf("Error: Some blocks are already allocated or invalid! Try again.\n");
        }

        printf("Enter more files? (1-Yes / 0-No): ");
        scanf("%d", &c);

        if (c != 1) {
            printf("Exiting program...\n");
            break;
        }
    }
    return 0;
}
