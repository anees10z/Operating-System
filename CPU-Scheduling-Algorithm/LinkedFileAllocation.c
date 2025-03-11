#include <stdio.h>

int main() {
    int n, start, next, count = 0;
    
    printf("Enter total number of blocks: ");
    scanf("%d", &n);

    int disk[n]; // Array to track allocation
    for (int i = 0; i < n; i++)
        disk[i] = -1; // Initialize as free

    printf("Enter starting block: ");
    scanf("%d", &start);

    if (start >= n) {
        printf("Error: Invalid starting block!\n");
        return 0;
    }

    int current = start;
    printf("Enter up to %d block links (-1 to stop):\n", n - 1);

    while (count < n - 1) { // Ensure it doesn't exceed disk size
        scanf("%d", &next);
        if (next == -1) break;
        if (next >= n || disk[next] != -1) { // Check validity
            printf("Error: Invalid or already allocated block!\n");
            continue;
        }
        disk[current] = next;
        current = next;
        count++;
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
