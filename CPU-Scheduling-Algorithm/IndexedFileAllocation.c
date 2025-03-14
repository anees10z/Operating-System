#include <stdio.h>
#define MAX 50 // Maximum number of blocks

int f[MAX], index[MAX]; // Disk block status and index table

int main() {
    int n, ind, i, count, c;
    for (i = 0; i < MAX; i++) f[i] = 0; // Initialize all blocks as free

    while (1) {
        printf("Enter index block: ");
        scanf("%d", &ind);
        if (f[ind]) {
            printf("Index block already allocated! Try another.\n");
            continue;
        }
        
        printf("Enter number of blocks needed: ");
        scanf("%d", &n);
        printf("Enter block numbers: ");
        count = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);
            if (!f[index[i]]) count++;
        }
        
        if (count == n) {
            f[ind] = 1;
            for (i = 0; i < n; i++) f[index[i]] = 1;
            printf("Allocated\nFile Indexed\n");
            for (i = 0; i < n; i++)
                printf("%d -> %d\n", ind, index[i]);
        } else {
            printf("Some blocks are already allocated! Try again.\n");
        }
        
        printf("Enter more files? (1-Yes / 0-No): ");
        scanf("%d", &c);
        if (!c) break;
    }
    return 0;
}
