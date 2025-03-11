#include <stdio.h>

int main() {
    int total_blocks, start, length, i, flag = 0;
    
    printf("Enter total number of disk blocks: ");
    scanf("%d", &total_blocks);

    int disk[total_blocks]; // Array to track allocated blocks

    // Initialize disk (0 = free, 1 = allocated)
    for (i = 0; i < total_blocks; i++)
        disk[i] = 0;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks required: ");
    scanf("%d", &length);

    // Check if allocation is possible
    if (start + length > total_blocks) {
        printf("Error: Not enough space available!\n");
        return 0;
    }

    for (i = start; i < start + length; i++) {
        if (disk[i] == 1) { // Block already allocated
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Error: Some blocks are already allocated!\n");
    } else {
        for (i = start; i < start + length; i++)
            disk[i] = 1; // Mark blocks as allocated

        printf("Allocated Blocks: ");
        for (i = start; i < start + length; i++)
            printf("%d ", i);

        printf("\nFile allocated successfully!\n");
    }

    return 0;
}
