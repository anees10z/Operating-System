#include <stdio.h> // Input-output ke liye
#include <stdlib.h> // abs() ke liye

int main() {
    int queue[] = {86, 147, 91, 177, 94, 150, 102}; // Request queue
    int n = 7; // Number of requests
    int head = 143; // Initial head position
    int seek = 0; // Total seek time
    
    printf("FCFS Order: ");
    for (int i = 0; i < n; i++) { // Har request ke liye
        printf("%d ", queue[i]); // Request print
        seek += abs(head - queue[i]); // Seek time = |current head - request|
        head = queue[i]; // Head ko nayi position pe move
    }
    printf("\nTotal Seek Time: %d\n", seek); // Total seek time
    
    return 0; // Program end
}
