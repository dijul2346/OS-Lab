#include <stdio.h>
struct process{
int pid,at,bt,ct,tat,wt,dbt;
}p[10],temp;
int n,i,j,k;
int t,count=0;
float ttat=0,twt=0;
void startsort(){
    for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(p[j].at>p[j+1].at){
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
for(i=0;i<n-1;i++){
for(j=0;j<n-i-1;j++){
if(p[j].at==p[j+1].at && p[j].bt>p[j+1].bt){
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
}
void burstsort(int start, int end){
    int i;
    int low=start;
    for(i=start+1;i<end;i++){
        if(p[low].dbt>p[i].dbt)
            low=i;
        if(p[low].dbt==p[i].dbt && p[low].at>p[i].at)
            low=i;
    }
    if(low!=start){
        temp=p[start];
        p[start]=p[low];
        p[low]=temp;
    }
}
void main(){
    int a[100];
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
p[i].pid=(i+1);
printf("Enter the arrival time of %d : ",(i+1));
scanf("%d",&p[i].at);
printf("Enter the burst time of %d : ",(i+1));
scanf("%d",&p[i].bt);
p[i].dbt=p[i].bt;
}
startsort();
t=p[0].at+1;
p[0].dbt--;
a[0]=p[0].pid;
while(count!=n){
   if(p[count].dbt==0){
       p[count].ct=t;
       p[count].tat=p[count].ct-p[count].at;
       ttat+=p[count].tat;
       p[count].wt=p[count].tat-p[count].bt;
       twt+=p[count].wt;
       count++;
    }
   k=count;
   if(p[count].at>t){
       a[t]=0;
       t++;
   }
   else{
       while(p[k].at<=t && k<n){
           k++;
       }
       if(count+1!=k)
           burstsort(count,k);
       p[count].dbt--;
       a[t]=p[count].pid;
       t++;
   }
}


printf("PID\tAT\tBT\tCT\tTAT\tWT\tDBT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].dbt);
}
printf("\n");
for(i=0;i<t-1;i++){
   if(a[i]==0)
       printf("//");
   else if(i!=0 && a[i-1]==a[i])
       printf("  ");
   else
       printf("|P%d",a[i]);
}
printf("|\n");
for(i=0;i<t-1;i++){
   if((i==0 && a[i]==0 ) || (i!=0 && a[i]==0 && a[i-1]!=0))
       printf("%d ",i);
   else if(i!=0 && a[i-1]==a[i])
       printf("  ");
   else
       printf("%d  ",i);
}
printf("%d\n",t-1);
printf("average turn-around time=%.2f\naverage waiting time=%.2f",(ttat)/n,(twt)/n);
}