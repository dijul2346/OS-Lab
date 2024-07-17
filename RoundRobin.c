#include <stdio.h>

struct process {
    int pid;
    int at, bt, ct, wt, tat, dbt, check;
} p[10], temp;

int n;
int c = 0, idle = 0, ct;
int time;
int A[100];
int rq[30], rear = -1, front = 0;

void startsort() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[i].at > p[i + 1].at) {
                temp = p[i];
                p[i] = p[i + 1];
                p[i + 1] = temp;
            }
        }
    }
}

void reduce(int a) {
    for (int i = 0; i < time; i++) {
        if (p[a].dbt != 0) {
            p[a].dbt--;
            A[ct] = p[a].pid;
            ct++;
        }
    }
    if (p[a].dbt == 0) {
        p[a].ct = ct;
        p[a].tat = p[a].ct - p[a].at;
        p[a].wt = p[a].tat - p[a].bt;
        c++;
        while (ct < p[a + 1].at) {
            A[ct] = 0;
            ct++;
        }
    }
}

void main() {
    int sturn = 0, swait = 0, temp1 = 0;
    float avgturn = 0, avgwait = 0;
    printf("Enter the number of processes ");
    scanf("%d", &n);
    int i;
    printf("Enter the time slice ");
    scanf("%d", &time);
    for (i = 0; i < n; i++) {
        printf("Enter the id of process %d ", (i + 1));
        scanf("%d", &p[i].pid);
        printf("Enter the at of process %d ", (i + 1));
        scanf("%d", &p[i].at);
        printf("Enter the bt of process %d ", (i + 1));
        scanf("%d", &p[i].bt);
        p[i].dbt = p[i].bt;

        p[i].ct = 0;
        p[i].wt = 0;
        p[i].tat = 0;
        p[i].check = 0;
    }
    startsort();
    ct = p[0].at;
    for (int i = 0; i < ct; i++) {
        A[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (p[i].at <= ct) {
            rear++;
            rq[rear] = p[i].pid;
            p[i].check = 1;
        }
    }
    do {
        for (int i = 0; i < n; i++) {
            if (p[i].pid == rq[front]) {
                reduce(i);
                front++;
                temp1 = i;
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (p[i].at <= ct && p[i].check == 0 && p[i].ct == 0) {
                rear++;
                rq[rear] = p[i].pid;
                p[i].check = 1;
            }
        }
        if (p[temp1].dbt != 0) {
            rq[++rear] = p[temp1].pid;
        }
    } while (c < n);
    printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for (int l = 0; l < n; l++) {
        sturn += p[l].tat;
        swait += p[l].wt;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[l].pid, p[l].at, p[l].bt, p[l].ct, p[l].tat, p[l].wt);
    }
    for (int i = 0; i < ct; i++) {
        if ((i == 0 && A[i] > 0) || (A[i] != A[i - 1] && A[i] > 0)) {
            printf("|P%d", A[i]);
        } else if (A[i] == A[i + 1]) {
            printf("  ");
        }
        if (A[i] == 0) {
            printf("||");
        }
    }
    printf("|\n");
    for (int i = 0; i < ct; i++) {
        if ((i == 0 && A[i] > 0) || (A[i] != A[i - 1] && A[i] > 0)) {
            printf("%d  ", i);
        } else if (A[i] == A[i + 1]) {
            printf("  ");
        }
        if (A[i] == 0) {
            printf("%d  ", i);
        }
    }
    printf("%d\n", ct);
    avgwait = swait / n;
    avgturn = sturn / n;
    printf("Average waiting time = %f", avgwait);
    printf("Average turnaround time = %f", avgturn);
    printf("\n");
}
