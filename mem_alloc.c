#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid,msize,wspace,bid,bsize,pflag;
}p[10];
struct blocks{
    int bid,bsize,bflag;
}b[10];
int pn,bn;

void readmemory(){
    printf("Enter the number of process to be allocated");
    scanf("%d",&pn);
    for(int i=0;i<pn;i++){
        printf("Enter the size of process %d",i);
        scanf("%d",&p[i].msize);
        p[i].pid=i+1;
        p[i].pflag=0;
    }
}

void readblocks() {
    printf("\nEnter the number of memory blocks available: ");
    scanf("%d", &bn);
    for (int i = 0; i < bn; i++) {
        printf("Enter the memory available for B%dth block: ", i + 1);
        scanf("%d", &b[i].bsize);
        b[i].bid = i + 1;
        b[i].bflag = 0;
    }
}

void reset() {
    for (int i = 0; i < pn; i++) {
        p[i].pflag = 0;
    }
    for (int i = 0; i < bn; i++) {
        b[i].bflag = 0;
    }
}

void table(){
    printf("\nProcess\t\tSize\tBlock id\tBlock Size\tWasted space\n");
    for(int i=0;i<pn;i++){
        if(p[i].pflag==1){
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].msize,p[i].bid,p[i].bsize,p[i].wspace);
        }
        else{
            printf("Process P%d cannot be allocated\n", i + 1);
        }
    }
}

void firstfit(){
    for(int i=0;i<pn;i++){
        for(int j=0;j<bn;j++){
            if(p[i].msize<=b[j].bsize && p[i].pflag==0 && b[j].bflag==0){
                p[i].pflag=1;
                b[j].bflag=1;
                p[i].bid=j;
                p[i].bsize=b[j].bsize;
                p[i].wspace=b[j].bsize-p[i].msize;
                break;

            }
        }
    }
    table();
    reset();
}

void worstfit(){
    for(int i=0;i<pn;i++){
        int worst=0;
        int flag=0;
        for(int j=0;j<bn;j++){
            if(p[i].msize<b[j].bsize && b[j].bflag==0 && (flag==0 || b[j].bsize>b[worst].bsize)){
                worst=j;
                flag=1;
            }
        }
    if(flag==1){
        p[i].bsize=b[worst].bsize;
        p[i].bid=b[worst].bid;
        p[i].wspace=b[worst].bsize-p[i].msize;
        b[worst].bflag=1;
        p[i].pflag=1;


    }}
    table();
    reset();
}

void bestfit(){
    for(int i=0;i<pn;i++){
        int best;
        int flag=0;
        for(int j=0;j<bn;j++){
            if(p[i].msize<=b[j].bsize && (flag==0 || b[j].bsize<b[best].bsize)&& b[j].bflag==0){
                flag=1;
                best=j;
            }
        }

        if(flag==1){
            p[i].bsize=b[best].bsize;
            p[i].bid=b[best].bid;
            p[i].wspace=b[best].bsize-p[i].msize;
            p[i].pflag=1;
            b[best].bflag=1;
        }
    }
    table();
    reset();
}
int main() {
    int x;
    readmemory();
    readblocks();
    while (1) {
        printf("\n1. First Fit\n2. Worst Fit\n3. Best Fit\n4. Exit\nEnter your choice: ");
        scanf("%d", &x);
        switch (x) {
            case 1:
                firstfit();
                break;
            case 2:
                worstfit();
                break;
            case 3:
                bestfit();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid Input\n");
        }
    }
    return 0;
}

