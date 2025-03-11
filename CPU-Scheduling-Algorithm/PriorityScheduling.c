#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], tat[n], wt[n], p[n];
    float total_tat = 0, total_wt = 0;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        p[i] = i + 1; // Store process number
    }

    // Sorting by priority (lower number = higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) { 
                int temp;
                
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    int time = 0;
    
    for (i = 0; i < n; i++) {
        if (time < at[i]) 
            time = at[i]; // Handle CPU idle time

        ct[i] = time + bt[i]; // Completion Time
        time = ct[i]; // Update current time
    }

    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i]; // Turnaround Time
        wt[i] = tat[i] - bt[i]; // Waiting Time

        total_tat += tat[i];
        total_wt += wt[i];

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage TAT: %.2f", total_tat / n);
    printf("\nAverage WT: %.2f\n", total_wt / n);

    return 0;
}
