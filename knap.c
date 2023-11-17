#include <stdio.h>
int dp[20][20];

int max(int a,int b){ return a>b?a:b;}

int kp(int wt[],int val[],int n,int w)
{
if(n==0 || w==0) return dp[n][w]=0;
if(dp[n][w]!=-1) return dp[n][w];
if(wt[n-1]<=w) return dp[n][w]=max(val[n-1]+dp[n-1][w-wt[n-1]],dp[n-1][w]);
return dp[n][w]=dp[n-1][w];
}

int main()
{
int n,w;
printf("enter n:");
scanf("%d",&n);
int wt[n],val[n];
printf("enter w=");
scanf("%d",&w);


for(int i=0;i<=n;i++)
{
for(int j=0;j<=w;j++)
{
dp[i][j]=-1;
}
}

printf("enter wt[]=");
for(int i=0;i<n;i++)scanf("%d",&wt[i]);
printf("enter val[]=");
for(int i=0;i<n;i++)scanf("%d",&val[i]);
int r=kp(wt,val,n,w);
printf("min=%d",r);


for(int i=0;i<=n;i++)
{
for(int j=0;j<=w;j++)
{
printf("%d ",dp[i][j]);
}
printf("\n");
}


}
