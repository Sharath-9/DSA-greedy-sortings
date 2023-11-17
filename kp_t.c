#include <stdio.h>


int max(int a,int b) {return a>b?a:b;}

int t[10][10];
int kp(int wt[10],int val[10],int n,int w)
{
for(int i=0;i<=n;i++)
{
for(int j=0;j<=w;j++)
{
if(i==0 || j==0) t[i][j]=0;
else if(wt[i-1]<=j) t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
else t[i][j]=t[i-1][j];
}

}
return t[n][w];

}


int main()
{
int n=5,wt[]={2,3,4,5,6},w=8,val[]={20,30,50,70,10};

for(int i=0;i<=n;i++)
{
for(int j=0;j<=w;j++)
t[i][j]=0;
}


int r=kp(wt,val,n,w);
printf("min=%d",r);
/*
for(int i=0;i<=n;i++)
{
for(int j=0;j<=w;j++)
printf("%d ",t[i][j]);
printf("\n");
}

*/

}
