#include <stdio.h>
#include <limits.h>

int dp[20][20];

int fsum(int f[10],int low,int high)
{
int sum=0;
for(int i=low;i<=high;i++)
sum=sum+f[i];

return sum;
}


int obst(int f[10],int i,int j,int dp[20][20])
{
if(dp[i][j]!=-1) return dp[i][j];
if(i>j) return dp[i][j]=0;
if(i==j) return dp[i][j]=f[i];
int min=INT_MAX;

for(int k=i;k<=j;k++)
{
int val=dp[i][k-1]+dp[k+1][j];
if(val<min) min=val;
}
return dp[i][j]=min+fsum(f,i,j);

}

int main()
{
int n;
printf("enter n:");
scanf("%d",&n);
int f[n];

for(int i=0;i<=n;i++)
{
for(int j=0;j<=n;j++)
{
dp[i][j]=-1;
}
}

printf("ener f array:");
for(int i=0;i<n;i++)
scanf("%d",&f[i]);
int r=obst(f,0,n-1,dp);

printf("%d\n",r);


for(int i=0;i<=n;i++)
{
for(int j=0;j<=n;j++)
{
printf("%d ",dp[i][j]);
}
printf("\n");
}




}
