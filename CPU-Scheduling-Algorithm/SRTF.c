#include <stdio.h>

int main() {
    int n, i, time = 0, smallest, finished = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    for (i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // Remaining time = Burst time initially
    }

    while (finished < n) {
        smallest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && (smallest == -1 || rt[i] < rt[smallest]))
                smallest = i;
        }

        if (smallest == -1) {
            time++; // If no process is available, move time forward
            continue;
        }

        rt[smallest]--; // Execute process for 1 unit
        time++;

        if (rt[smallest] == 0) { // If process completes
            finished++;
            ct[smallest] = time;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];  
        wt[i] = tat[i] - bt[i];  
        total_tat += tat[i];
        total_wt += wt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT: %.2f", total_tat / n);
    printf("\nAvg WT: %.2f\n", total_wt / n);

    return 0;
}
