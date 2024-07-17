#include<stdio.h>

int alloc[30][30],max[30][30],need[30][30],vis[30],avail[30],seq[30],dupavail[30];
int i,j,k,p,r,ind=0;;

void main(){
    printf("Enter the number of process");
    scanf("%d",&p);
    printf("Enter the number of resouces");
    scanf("%d",&r);

    printf("Enter the allocation matrix");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter the max allocation matrix");
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }

    
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    printf("Enter the available resources : ");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
        dupavail[i]=avail[i];
    }

    for(int i=0;i<p;i++){
        vis[i]=0;
    }

    for(k=0;k<p;k++){
        for(i=0;i<p;i++){
            if(vis[i]==0){
                int flag=0;

                for(j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    vis[i]=1;
                    seq[++ind]=i;
                    for(int x=0;x<r;x++){
                        avail[x]=avail[x]+alloc[i][x];
                    }
                }
            }
        }
    }

    int flag=1;
    for(i=0;i<p;i++)
    {
        if(vis[i]==0)
        {
            flag=0;
            printf("Not a safe sequence");
        }
    }

    if(flag==1)
    {
        for(i=0;i<p-1;i++)
        {
            printf("P%d -- ",seq[i]);
        }printf("P%d ",seq[i]);
    }
    int req,new[r];
   printf("Enter request process");
   scanf("%d",&req);
   printf("Enter the resoucrces");
   for(int i=0;i<r;i++){
    scanf("%d",&new[i]);
   }

   for(int j=0;j<r;j++){
        flag=0;
        if(new[j]>=need[req][j]){
            flag=1;
            break;
        }
   }
   if(flag==0){
        for(int i=0;i<r;i++){
            alloc[req][i]=alloc[req][i]+new[i];
            need[req][i]=need[req][i]-new[i];
            avail[i]=dupavail[i]-new[i];

        }
   }
   printf("Available Matrix : ");
   for(int i=0;i<r;i++){
    printf("%d ",&avail[i]);
   }

   for(int i=0;i<p;i++){
        vis[i]=0;
    }

    for(k=0;k<p;k++){
        for(i=0;i<p;i++){
            if(vis[i]==0){
                int flag=0;

                for(j=0;j<r;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }

                if(flag==0){
                    vis[i]=1;
                    seq[++ind]=i;
                    for(int x=0;x<r;x++){
                        avail[x]=avail[x]+alloc[i][x];
                    }
                }
            }
        }
    }

    flag=1;
    for(i=0;i<p;i++)
    {
        if(vis[i]==0)
        {
            flag=0;
            printf("Not a safe sequence");
        }
    }

    if(flag==1)
    {
        for(i=0;i<p-1;i++)
        {
            printf("P%d -- ",seq[i]);
        }printf("P%d ",seq[i]);
    }

}