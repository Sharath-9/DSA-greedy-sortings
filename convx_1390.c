#include <stdio.h>
struct point
{
int x;
int y;
};

void convex_hull(struct point p[10],int n)
{
for(int i=0;i<n-1;i++)
{
for(int j=i+1;j<n;j++)
	{
	int a,b,c,nn=0,np=0;
	a=p[i].y-p[j].y;
	b=p[j].x-p[i].x;
	c=p[j].y*p[i].x-p[i].y*p[j].x;
	
	for(int k=0;k<n;k++)
	{
	int s=a*p[k].x+b*p[k].y+c;
	if(s<0) nn++;
	else if(s>0) np++;
	}
	
	if(nn==0 || np==0) printf("(%d,%d)--(%d,%d)\n",p[i].x,p[i].y,p[j].x,p[j].y);
	
	}
}
}

int main()
{
int n;
printf("enter n:");
scanf("%d",&n);
struct point p[n];
printf("enter points: ");
for(int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);

convex_hull(p,n);
}
