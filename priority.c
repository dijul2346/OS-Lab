#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid,at,bt,ct,tat,wt,prio,v;
}p[10],temp;

int n,min,time=0,count=0; 



void main(){
    printf("Enter the number of process");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the process id: ");
        scanf("%d", &p[i].pid);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter the priority : ");
        scanf("%d",&p[i].prio);
        p[i].v=0;
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
    
    time=p[0].at;
    p[0].ct=time+p[0].bt;
    time=p[0].ct;
    p[0].v=1;
    count++;

    p[19].prio=1000;

    while(count<n){
        
        int flag=0,min=19;

        for(int i=0;i<n;i++){
            if(p[i].at<time && p[i].v==0 && p[i].prio<=p[min].prio){
                min=i;
                flag=1;
            }
        }

        if(flag==1){
        p[min].ct=time+p[min].bt;
        time=p[min].ct;
        p[min].v=1;
        count++;
        }
        else{
            time++;
        }
    }

    printf("\nPid\tArrival time\tBurst Time\tPriority\tCompletion Time\tTurnAround Time\tWait Time\n");
        for (int i = 0; i < n; i++) {
            p[i].tat= p[i].ct-p[i].at;
            p[i].wt= p[i].tat-p[i].bt;
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt,p[i].prio, p[i].ct, p[i].tat, p[i].wt);
        }
    

}
