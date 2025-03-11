#include <stdio.h>

int main() {
    int n, start, next, i;
    
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    int disk[n]; // Array to store links

    for (i = 0; i < n; i++)
        disk[i] = -1; // Initialize all blocks as free (-1 means no link)

    printf("Enter starting block: ");
    scanf("%d", &start);

    int current = start;
    printf("Enter block links (-1 to stop):\n");

    while (1) {
        scanf("%d", &next);
        if (next == -1) break;
        disk[current] = next; // Link current block to next
        current = next;
    }

    printf("\nAllocated Blocks:\n");
    current = start;
    while (current != -1) {
        printf("%d -> ", current);
        current = disk[current];
    }
    printf("NULL\n");

    return 0;
}
