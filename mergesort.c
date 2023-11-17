#include<stdio.h>
int merge(int a[],int lb,int mid,int ub)
{
int i,j,k,b[50];
i=lb;
j=mid+1;
k=lb;
while(i<=mid &&j<=ub)
{
if(a[i]<=a[j])
{
b[k]=a[i];
i++;
k++;
}
else
{
b[k]=a[j];
j++;
k++;
}
}
if(j<=ub)
{
b[k]=a[j];
j++;
k++;
}
else
{
b[k]=a[i];
i++;
k++;
}
for(i=lb;i<=ub;i++)
{
a[k]=b[k];
}

}
int mergesort (int a[],int lb,int ub)
{
int mid;
if(lb<ub)
{
mid=(lb+ub)/2;
mergesort(a,lb,mid);
mergesort(a,mid+1,ub);
merge(a,lb,mid,ub);
}
}
void main()
{
int i,j,n,lb=0,ub=n-1;
printf("enter size oof array");
scanf("%d",&n);
int a[n];
printf("enter elements into array");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
mergesort(a,lb,ub);
printf("sorted array is\n");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
}


