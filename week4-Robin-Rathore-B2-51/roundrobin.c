#include<stdio.h>
#include<stdbool.h>

struct process {
    int pid, at, bt, r_bt;
    int tat, ct, wt;
};

// Function to calculate completion times
void calculateTimes(struct process ps[], int n, int quanta) {
    int currTime = 0;  // Keeps track of current time
    bool isCompleted = false;
    printf("\nGantt Chart:\n");

    while (!isCompleted) {
        isCompleted = true;  // Assume all processes are completed at the start

        for (int i = 0; i < n; ++i) {
            // Only consider processes that are yet to complete (remaining burst time > 0)
            if (ps[i].r_bt > 0) {
                isCompleted = false;  // Since at least one process is still remaining

                if (ps[i].r_bt > quanta) {
                    // Process runs for a full quantum
                    printf("| P%d ", ps[i].pid);  // Gantt chart printing
                    ps[i].r_bt -= quanta;
                    currTime += quanta;
                } else {
                    // Process completes within the remaining burst time
                    printf("| P%d ", ps[i].pid);  // Gantt chart printing
                    currTime += ps[i].r_bt;
                    ps[i].r_bt = 0;
                    ps[i].ct = currTime;  // Completion time
                }
            }
        }
    }
    printf("|\n");
}

// Function to calculate Turnaround Time
void calculateTaTime(struct process ps[], int n) {
    for (int i = 0; i < n; ++i) {
        ps[i].tat = ps[i].ct - ps[i].at;  // Turnaround Time = Completion Time - Arrival Time
    }
}

// Function to calculate Waiting Time
void calculateWaTime(struct process ps[], int n) {
    for (int i = 0; i < n; ++i) {
        ps[i].wt = ps[i].tat - ps[i].bt;  // Waiting Time = Turnaround Time - Burst Time
    }
}

// Function to print process details
void print(struct process ps[], int n) {
    printf("\nPID\t| AT\t| BT\t| CT\t| TAT\t| WT\n");
    for (int i = 0; i < n; ++i) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tat, ps[i].wt);
    }
}

int main() {
    printf("Name : Robin Rathore\nSection : B2\nRoll No.: 51\n");
    int n, quanta;
    printf("Enter the number of Processes and Quanta: ");
    scanf("%d %d", &n, &quanta);

    struct process ps[n];
    printf("Enter the process Arrival Time and Burst Time:\n");

    for (int i = 0; i < n; ++i) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &ps[i].at, &ps[i].bt);
        ps[i].pid = i + 1;    // Process ID
        ps[i].r_bt = ps[i].bt; // Initialize remaining burst time
    }

    // Calculate times using the Round Robin approach
    calculateTimes(ps, n, quanta);
    calculateTaTime(ps, n);
    calculateWaTime(ps, n);

    // Print final results
    print(ps, n);
    
    // Calculate average waiting time and turnaround time
    float AWT = 0.0, ATAT = 0.0;
    for (int i = 0; i < n; ++i) {
        AWT += ps[i].wt;
        ATAT += ps[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f\n", AWT / n);
    printf("Average Turn Around Time: %.2f\n", ATAT / n);

    return 0;
}
