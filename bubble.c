#include<stdio.h>
void swap(int *a, int *b){
int temp=*a;
*a=*b;
*b=temp;
}
void bubblesort(int A[],int n){
int i,j;
int flag=0;
for(i=0;i<n-1;i++){
flag=0;
for(j=0;j<n-i-1;j++)
{
if(A[j]>A[j+1]){
swap(&A[j],&A[j+1]);
flag=1;
}
}
if(flag==0) break;
}
}




void insertsort(int B[],int n){
int i,j;
for(i=1;i<n;i++){
j=i-1;
int x=B[i];
while(j>-1&&B[j]>x){
B[j+1]=B[j];
j--;
}
B[j+1]=x;
}
}




void selectsort(int C[], int n){
int i,j,k;
for(i=0;i<n-1;i++){

for(j=k=i;j<n;j++){
if(C[j]<C[k])
k=j;
}

swap(&C[i],&C[k]);
}printf("Sorted array\n");
for( i=0;i<n;i++){
printf("%d->",C[i]);
}printf("NULL");
}



int partition(int a[],int l, int h){
 int pivot=a[h];
 int i=(l-1);
 int j;
 for(j=l;j<=h-1;j++){
 if(a[j]<pivot){
 i++;
 swap(&a[i],&a[j]);
 }
 }
 swap(&a[i+1],&a[h]);
 return (i+1);
 }
 
 
 
 
 void quicksort(int a[],int l, int h){
 if(l<h){
 int p=partition(a,l,h);
   quicksort(a,l,p-1);
   quicksort(a,p+1,h);
   }
   }
  
   
int main(){
int i;
int A[]={3,7,2,5,1},z=5;
printf("UNsorted array\n");
for(  i=0;i<5;i++){

printf("%d->",A[i]);
}printf("NULL\n");

bubblesort(A,z);
printf("Bubblesort\n");
for(  i=0;i<5;i++){
printf("%d->",A[i]);
}printf("NULL");


int B[]={1,70,21,666,71,9,3,75,88,11},x=10;
for( i=0;i<10;i++){
printf("%d->",B[i]);
}printf("NULL\n");
int C[]={1,70,21,666,71,9,3,75,88,11},y=10;
for( i=0;i<10;i++){
printf("%d->",C[i]);
}printf("NULL\n");
/*printf("\ninsertionsort\n");
insertsort(B,x);
for(  i=0;i<10;i++){
printf("%d ",B[i]);
}
printf("for selection sort");
selectsort(C,y);
printf("sorting technique for quicksort\n");
int a[]={3,7,9,10,6,12,4,11,2,8},n=10;
printf("Unsorted array \n");
   for(i=0;i<10;i++){
   printf("%d->",a[i]);
   }printf("NULL");
   printf("sorted array \n");
   quicksort(a,0,n-1);
   for(i=0;i<10;i++){
   printf("%d->",a[i]);
   }printf("NULL\n");*/
   }

