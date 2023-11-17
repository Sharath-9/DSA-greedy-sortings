#include <stdio.h>
#include <limits.h>
int t[10][10];


int fsum(int f[10],int low,int high)
{
int sum=0;
for(int i=low;i<=high;i++)
sum=sum+f[i];

return sum;
}


void obst(int f[10],int low,int n)
{
for(int m=0;m<n;m++)
{
for(int i=1;i<=n-m;i++)
{
int j=i+m;
if(i==j) t[i][j]=f[i];
else if(i>j) t[i][j]=0;
else
{
int min=INT_MAX;
for(int k=i;k<=j;k++)
{
int v=t[i][k-1]+t[k+1][j];
if(v<min) min=v;
}
t[i][j]=min+fsum(f,i,j);
}
}
}


}



int main()
{
int n=5,f[]={0,20,30,50,60};
obst(f,1,n);

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
printf("%d ",t[i][j]);
printf("\n");
}



}
