#include<stdio.h>
#include<stdlib.h>
int main(){
int n,ne=1,cost[10][10],i,j;
printf("enter the value f n:");
scanf("%d",&n);
printf("enter the value cost array:");
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
scanf("%d",&cost[i]][j])
if(cost[i][j]==0)
{
 cost[i][j]=999
}
}
prims(n,cost);
return 0;
}


void prims(int n,int cost[10][10])
{
int i,j,n,ne=1,u,v,min,mincost=0,visited[10];



}
