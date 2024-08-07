#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int disk[20],head,seek,n,i,j,k,allocated[20];

void display(){

    seek=0;
    printf(" order of allocation : ");
    for(i=0;i<j-1;i++){
        printf("%d ->",allocated[i]);
        if(i==0){
            seek=abs(head-allocated[i]);
        }
        else{
            seek+=abs(allocated[i]-allocated[i-1]);
        }

    }
    printf("%d ",allocated[i]);
    seek+=abs(allocated[i]-allocated[i-1]);
    printf("\nSeek time= %d", seek);

}

void fcfs(){
    printf("Enter the head");
    scanf("%d",&head);
    for(i=0,j=0;i<n;i++){
        if(disk[i]<200){
            allocated[j]=disk[i];
            j++;
        }
    }
    display();
}

void scan(){
    printf("Enter the head");
    scanf("%d",&head);
    for(i=head,j=0;i>=0;i--){
        for(k=0;k<n;k++){
            if(disk[k]==i){
                allocated[j]=disk[k];
                j++;
            }
        }

    }
    allocated[j]=199;
    j++;
    for(i=head+1;i<200;i++){
        for(k=0;k<n  ;k++){
            if(disk[k]==i){
                allocated[j]=disk[k];
                j++;
            }
        }
    }
    display();
}

void cscan(){
    printf("Enter the head : ");
    scanf("%d",&head);
    for(i=head,j=0;i<=199;i++){
        for(k=0;k<n;k++){
            if(disk[k]==i){
                allocated[j]=disk[k];
                j++;
            }
        }
    }

    for(i=0;i<head;i++){
        for(k=0;k<n;k++){
            if(disk[k]==i){
                allocated[j]=disk[k];
                j++;
            }
        }
    }
    display();
}






void main() {
    int x;
    printf("Enter the number of processes to be allocated: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the disk space: ");
        scanf("%d", &disk[i]);
    }
    while (1) {
        printf("\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit\nEnter your choice: ");
        scanf("%d", &x);
        switch (x) {
            case 1: fcfs(); break;
            case 2: scan(); break;
            case 3: cscan(); break;
            case 4: exit(0); break;
            default: printf("Invalid Input\n");
        }
    }
}
