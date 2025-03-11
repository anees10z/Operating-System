#include <stdio.h>

int main() {
    int n, quantum, i, time = 0, completed = 0;
    
    printf("Enter number of processes and time quantum: ");
    scanf("%d %d", &n, &quantum);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    for (i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while (completed < n) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && at[i] <= time) {
                done = 0;
                if (rt[i] > quantum) time += quantum, rt[i] -= quantum;
                else time += rt[i], rt[i] = 0, ct[i] = time, completed++;
            }
        }
        if (done) time++;
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_tat += tat[i], total_wt += wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT: %.2f", total_tat / n);
    printf("\nAvg WT: %.2f\n", total_wt / n);

    return 0;
}
