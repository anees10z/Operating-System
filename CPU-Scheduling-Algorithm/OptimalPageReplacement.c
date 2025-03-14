#include <stdio.h>

#define MAX_FRAMES 3  // Number of frames
#define MAX_PAGES 12  // Number of page references

int predict(int pages[], int frames[], int index) {
    int farthest = index, replace = -1;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = index; j < MAX_PAGES; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replace = i;
                }
                break;
            }
        }
        if (j == MAX_PAGES) return i;
    }
    return (replace == -1) ? 0 : replace;
}

int main() {
    int pages[MAX_PAGES] = {7, 0, 1, 2, 0, 3, 4, 2, 3, 0, 3, 2}; // New Reference String
    int frames[MAX_FRAMES] = {-1, -1, -1}; // Initialize frames
    int pageFaults = 0;

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
            printf("%d %d %d | Page Hit \n", frames[0], frames[1], frames[2]);
        } else { // Page Fault
            int replaceIndex = (i < MAX_FRAMES) ? i : predict(pages, frames, i);
            frames[replaceIndex] = pages[i];
            pageFaults++;
            printf("%d %d %d | Page Fault \n", frames[0], frames[1], frames[2]);
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
    return 0;
}
