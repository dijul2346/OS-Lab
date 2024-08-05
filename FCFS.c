#include<stdio.h>

struct process{
    int pid,at,bt,ct,tat,wt;
}p[20],temp;

void main(){
    printf("Enter the number of process : ");
    int n=0,ct=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(p[j].at>p[j+1].at){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    
    p[0].ct=p[0].at+p[0].bt;
    p[0].tat=p[0].ct-p[0].at;
    p[0].wt=p[0].tat-p[0].bt;

    for(int i=1;i<n;i++){
        ct=p[i-1].ct;
        if(p[i].at>ct){
            p[i].ct=p[i].at+p[i].bt;
        }
        else{
            p[i].ct=ct+p[i].bt;
        }
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
    }

    printf("\nPid\tArrival time\tBurst Time\tCompletion Time\tTurnAround Time\tWait Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
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
