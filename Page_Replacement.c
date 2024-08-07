#include<stdio.h>
#include<stdlib.h>

int n,p,f,pages[20],frame[5],hit;
int refferenceBit[20],usedCount[20];

void fifo(){
	for(int i=0;i<f;i++){
		frame[i]=-1;
	}
	int x=0;
	for(int i=0;i<p;i++){
		int flag=0;
		for(int y=0;y<f;y++){
			if(frame[y]==pages[i]){
				flag=1;
				break;
			}	
		}
		
		if(flag==0){
			frame[x]=pages[i];
			x=(x+1)%f;
			printf("%d -> ",pages[i]);
			for(int j=0;j<f;j++){
				printf(" |%d",frame[j]);
			}
			printf(" |\n");
		}
		else{
			hit++;
			printf("%d -> \n",pages[i]);
		}
	}
	printf("No of pagefault = %d\n",(p-hit));
	printf("No of hits = %d\n",hit);
	printf("Hit Ratio = %.2f\n",(float)hit/p);
		
							
}

void lru(){
	for(int i=0;i<f;i++){
		frame[i]=-1;
	}
	int pageFaults = 0;
	hit=0;
	for (int i = 0; i < p; i++) {
		int flag = 0;
		for (int j=0;j<f;j++){
		    if (frame[j]==pages[i]){
		        flag = 1;
		        printf("%d ->\n",pages[i]);
		        hit++;
		        usedCount[pages[i]] = i;
		        break;
		    }}
	
		if (flag == 0) {
		    pageFaults++;
		    int leastUsed = 0;		
		    for (int j = 0; j < f; j++) {
		    	if(frame[j]==-1){
		    		leastUsed=j;
		    		break;
		    	}	
		        if (usedCount[frame[j]] < usedCount[frame[leastUsed]]) {
		            leastUsed = j;
		        }
		    }
		    frame[leastUsed] = pages[i];
		    usedCount[pages[i]] = i;
		    pageFaults++;
		    printf("%d -> ",pages[i]);
		    for(int j=0;j<f;j++){
				printf(" |%d",frame[j]);
			}
			printf(" |\n");
		}
   	 }	
   	 
   	 
   	 printf("No of pagefault = %d\n",(p-hit));
   	 printf("No of hits = %d\n",hit);
	 printf("Hit Ratio = %.2f\n",(float)hit/p);
}


void lfu(){
	int pageFaults = 0;
	for (int i=0;i<f;i++) {
		frame[i] = -1;
	}
	int flag=0;
	for (int i=0;i<p;i++) {
		refferenceBit[pages[i]]++;
		int frameIndex = -1;
		for (int j = 0; j < f; j++) {
		    if (frame[j]==pages[i]) {
		        frameIndex = j;
		        printf("%d ->\n",pages[i]);
		        break;
		    }
		}
		
		if (frameIndex == -1) {
		    int leastFreq = 0;
		    for (int j=0;j<f;j++){
		        if (refferenceBit[frame[j]] < refferenceBit[frame[leastFreq]]) {
		            leastFreq = j;
		        }
		    }
		    frame[leastFreq] = pages[i];
		    pageFaults++;
		    printf("%d -> ",pages[i]);
		    for(int j=0;j<f;j++){
				printf(" |%d",frame[j]);
			}
			printf(" |\n");    
		}
   	 }
   	 printf("No of page faults = %d\n",pageFaults);
   	 hit=p-pageFaults;
   	 printf("No of hits = %d\n",hit);
	 printf("Hit Ratio = %.2f\n",(float)hit/p);
}	



void optimal(){
	for(int i=0;i<f;i++){
		frame[i]=-1;
	}
	int pageFaults = 0;
	hit=0;
	for (int i = 0; i < p; i++) {
		int flag = 0;
		for (int j=0;j<f;j++){
		    if (frame[j]==pages[i]){
		        flag = 1;
		        printf("%d ->\n",pages[i]);
		        hit++;
		        usedCount[pages[i]] = i;
		        break;
		    }}
		for(int x=0;x<10;x++){
			usedCount[x]=0;
		}
		for(int k=i;k<p;k++){
			for(int j=0;j<f;j++){
				if(pages[k]==frame[j]){
					if(usedCount[pages[k]]==0){
						usedCount[pages[k]]=k;
					}	
				}
			}
		}		
	
		if (flag == 0) {
		    pageFaults++;
		    int leastUsed = 0;		
		    for (int j = 0; j < f; j++) {
		    	if(frame[j]==-1){
		    		leastUsed=j;
		    		break;
		    	}
		    	if(usedCount[frame[j]]==0){
		    		leastUsed=j;
		    		break;
		    	}	
		        if (usedCount[frame[j]] > usedCount[frame[leastUsed]]) {
		            leastUsed = j;
		        }
		    }
		    frame[leastUsed] = pages[i];
		    usedCount[pages[i]] = i;
		    pageFaults++;
		    printf("%d -> ",pages[i]);
		    for(int j=0;j<f;j++){
				printf(" |%d",frame[j]);
			}
			printf(" |\n");
		}
   	 }	
   	 
   	 
   	 printf("No of pagefault = %d\n",(p-hit));
   	 printf("No of hits = %d\n",hit);
	 printf("Hit Ratio = %.2f\n",(float)hit/p); 
}


void main(){
	// 2 1 2 3 4 2 5 1 3 2 4 2 4 1 5
	printf("Enter the number of pages");
	scanf("%d",&p);
	printf("Enter the frame size ");
	scanf("%d",&f);
	printf("Enter the pages : ");
	for(int i=0;i<p;i++){
		scanf("%d",&pages[i]);
	}
	int ch;
	do{
		printf("1)FIFO 2)LRU 3)LFU 4)Optimal 5)Exit\nEnter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("FIFO\n");
				fifo();
				break;
			
			case 2:
				printf("LRU\n");
				lru();
				break;
			case 3:
				printf("LFU\n");
				lfu();
				break;
			case 4:
				printf("Optimal\n");
				optimal();
				break;	
			case 5:
				break;	
			default:
				printf("Invalid choice ");	
			}
	}while(ch!=4);					
}
