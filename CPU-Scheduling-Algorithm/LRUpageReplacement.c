#include <stdio.h>

#define MAX_FRAMES 3  // Number of frames
#define MAX_PAGES 10  // Number of page references

int main() {
    int pages[MAX_PAGES] = {2, 3, 1, 5, 3, 4, 1, 2, 3, 5}; // New Reference String
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames
    int recent[MAX_FRAMES] = {0, 0, 0}; // Track usage order
    int pageFaults = 0, time = 0;

    printf("Page Reference | Frames       | Status\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        int found = -1;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = j;
                break;
            }
        }

        printf("       %d       | ", pages[i]);

        if (found != -1) { // Page Hit
            recent[found] = time++; // Update recent usage time
            printf("%d %d %d | Page Hit \n", frames[0], frames[1], frames[2]);
        } else { // Page Fault
            int lru = 0; // Find LRU page index
            for (int j = 1; j < MAX_FRAMES; j++)
                if (recent[j] < recent[lru])
                    lru = j;

            frames[lru] = pages[i];  // Replace LRU page
            recent[lru] = time++; // Update recent usage time
            pageFaults++;
            printf("%d %d %d | Page Fault \n", frames[0], frames[1], frames[2]);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
