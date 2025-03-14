#include <stdio.h>

#define MAX_FRAMES 3  // Number of frames
#define MAX_PAGES 7   // Number of page references

int main() {
    int pages[MAX_PAGES] = {1, 3, 0, 3, 5, 6, 3}; // Reference string
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames
    int front = 0, pageFaults = 0;

    printf("Page Reference | Frames       | Status\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        int found = 0;
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        printf("       %d       | ", pages[i]);
        if (found) {
            printf("%d %d %d | Page Hit \n", frames[0], frames[1], frames[2]);
        } else {
            frames[front] = pages[i];  // Replace oldest page
            front = (front + 1) % MAX_FRAMES; // Move FIFO pointer
            pageFaults++;
            printf("%d %d %d | Page Fault \n", frames[0], frames[1], frames[2]);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
