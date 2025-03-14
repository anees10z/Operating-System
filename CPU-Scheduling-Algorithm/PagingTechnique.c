#include <stdio.h>

#define PAGE_SIZE 4   // Page size (4KB)
#define TOTAL_PAGES 5 // Total pages in memory

int main() {
    int pageTable[TOTAL_PAGES]; // Page Table
    int logicalAddress, pageNumber, offset, physicalAddress;
    // Initialize Page Table (Mapping Logical to Physical Pages)
    printf("Initializing Page Table...\n");
    for (int i = 0; i < TOTAL_PAGES; i++) {
        pageTable[i] = i; // Mapping Logical Page -> Physical Page
        printf("Page %d -> Frame %d\n", i, pageTable[i]);
    }
    while (1) {
        // Input logical address
        printf("\nEnter Logical Address (0 - %d) or -1 to Exit: ", PAGE_SIZE * TOTAL_PAGES - 1);
        scanf("%d", &logicalAddress);
        // Exit Condition
        if (logicalAddress == -1) {
            printf("Exiting program...\n");
            break;
        }
        // Calculate Page Number and Offset
        pageNumber = logicalAddress / PAGE_SIZE;
        offset = logicalAddress % PAGE_SIZE;
        // Check if Page Number is valid
        if (pageNumber < TOTAL_PAGES) {
            physicalAddress = pageTable[pageNumber] * PAGE_SIZE + offset;
            printf("Page Number: %d\nOffset: %d\n", pageNumber, offset);
            printf("Logical Address: %d -> Physical Address: %d\n", logicalAddress, physicalAddress);
        } else {
            printf("Invalid Logical Address! Out of Bound.\n");
        }
    }
    return 0;
}
