#include<stdio.h>
#include<stdlib.h>

#define size 3
int pages[20];
int head=0;

void main(){
    int frames[size]={-1,-1,-1};
    int pageFaults=0,hits=0,n;

    printf("Enter the number of pages");
    scanf("%d",&n);

    printf("enter the pages");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    
    int flag=0;
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=0;j<size;j++){
            if(frames[j]==pages[i]){
                hits++;
                flag=1;
            }
        }

        if(flag==0){
            frames[head]=pages[i];
            head=head%3;
        }
        printf("frame : ");
        if(flag==0){
            for(int k=0;k<3;k++){
                printf("%d |",frames[k]);
            }
        }
    }
}