#include <stdio.h>
// FCFS algorithm without Arival Time
void main()
{
    int n;
    printf("Enter number of Process: ");
    scanf("%d", &n);

    int pid[n];
    int bt[n];
    int wt[n];
    int tat[n];

    printf("\nEnter Process id's :\n");
    for (int i = 0; i < n; ++i)
    {
        printf("Process %d id = ", i + 1);
        scanf("%d", &pid[i]);
    }

    // Burst time of processes
    printf("\nEnter burst time for Processes :\n");
    for (int i = 0; i < n; ++i)
    {
        printf(" Burst time of Process: P%d = ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // calculating waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // calculating Turn Around time
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
    // Display results in well-formatted table
    printf("\n----------------------------------------------\n");
    printf("| %-5s | %-10s | %-12s | %-15s |\n", "P-ID", "Burst Time", "Waiting Time", "Turnaround Time");
    printf("----------------------------------------------\n");

    for (int i = 0; i < n; ++i)
    {
        printf("| %-5d | %-10d | %-12d | %-15d |\n", pid[i], bt[i], wt[i], tat[i]);
    }
    printf("----------------------------------------------\n");
    // Calculate average waiting time and turnaround time
	float total_wt = 0, total_tat = 0;
	for (int i = 0; i < n; i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];
	}
	printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
	printf("Average Turnaround Time: %.2f\n", total_tat / n);
}
