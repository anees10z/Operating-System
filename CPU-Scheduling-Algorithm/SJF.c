#include <stdio.h> // Input-output ke liye library

int main() {
    int n = 4; // Number of processes (fixed rakha simplicity ke liye)
    int bt[4] = {6, 8, 7, 3}; // Burst times (P0=6, P1=8, P2=7, P3=3)
    int wt[4], tat[4], p[4] = {0, 1, 2, 3}; // Arrays: waiting time, turnaround time, process IDs
    
    // Sort processes by burst time (bubble sort)
    for (int i = 0; i < n-1; i++) // Outer loop for sorting
        for (int j = 0; j < n-i-1; j++) // Inner loop
            if (bt[j] > bt[j+1]) { // Agar current burst time bada hai
                int temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp; // Swap burst time
                temp = p[j]; p[j] = p[j+1]; p[j+1] = temp; // Swap process ID
            }
    
    wt[0] = 0; // Pehle process ka waiting time 0
    for (int i = 1; i < n; i++) // Baaki ke liye waiting time
        wt[i] = wt[i-1] + bt[i-1]; // Previous waiting time + previous burst time
    
    for (int i = 0; i < n; i++) // Turnaround time ke liye
        tat[i] = wt[i] + bt[i]; // Waiting time + burst time
    
    float avg_wt = 0, avg_tat = 0; // Average variables
    for (int i = 0; i < n; i++) { // Sum for averages
        avg_wt += wt[i]; // Waiting times ka sum
        avg_tat += tat[i]; // Turnaround times ka sum
    }
    
    // Print table
    printf("P-ID BT WT TAT\n"); // Header
    for (int i = 0; i < n; i++) // Har process ke details
        printf("P%d   %d  %d  %d\n", p[i], bt[i], wt[i], tat[i]);
    printf("Avg WT: %.2f, Avg TAT: %.2f\n", avg_wt/n, avg_tat/n); // Averages
    
    return 0; // Program end
}
