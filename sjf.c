#include<stdio.h>

struct process {
    int pid, at, bt, ct, tat, wt, ready;
} p[20], temp, queue[20];

int n, time = 0, rear = -1, front = 0;

void check(struct process p[], int n) {
    if (rear != n - 1) {
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].ready == 0) {
                queue[++rear] = p[i];
                p[i].ready = 1;
            }
        }
    }
}

void main() {
    printf("Enter the number of process: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter the process id: ");
        scanf("%d", &p[i].pid);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);
        p[i].ready = 0;
    }

    // Sort the processes by arrival time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Add the first process to the queue and set its completion time
    p[0].ct = p[0].at + p[0].bt;
    p[0].ready = 1;
    queue[++rear] = p[0];
    time = p[0].ct;

    // Process the remaining processes
    while (front <= rear) {
        check(p, n);
        
        // Find the shortest job in the queue
        int shortest = front;
        for (int i = front + 1; i <= rear; i++) {
            if (queue[i].bt < queue[shortest].bt || 
                (queue[i].bt == queue[shortest].bt && queue[i].at < queue[shortest].at)) {
                shortest = i;
            }
        }

        // Swap the shortest job to the front of the queue
        temp = queue[front];
        queue[front] = queue[shortest];
        queue[shortest] = temp;

        // Calculate completion time for the current process
        queue[front].ct = time + queue[front].bt;
        time = queue[front].ct;
        front++;
    }

    // Calculate turnaround time and waiting time for each process
    printf("\nPid\tArrival time\tBurst Time\tCompletion Time\tTurnAround Time\tWait Time\n");
    for (int i = 0; i < n; i++) {
        p[i].ct = queue[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].bt;j++){
            printf("--");
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].bt-1;j++){
            printf("  ");
        }
        printf("P%d |",p[i].pid);
    }
    printf("\n");
   printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].bt-1;j++){
            printf("  ");
        }
        printf(" %d  ",p[i].ct);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<p[i].bt;j++){
            printf("--");
        }
    }
    printf("\n");

}