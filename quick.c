
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap( int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
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
   int n;
    printf("enter the size of the array");
    scanf("%d",&n);
   int A[n],i;
   srand(time(NULL));//initialization 
   printf("enter the elements \n");
   for(i=0;i<n;i++){
   scanf("%d",&A[i]);
   // A[i]=rand() % 100;
    
   }
   
   printf("Unsorted array:");
   for(i=0;i<n;i++){
   printf("%d ",A[i]);
}
printf("\n");
clock_t start_time=clock();
quicksort(A,0,n-1);
clock_t end_time=clock();
printf("sorted array:");
   for(i=0;i<n;i++){
   printf("%d ",A[i]);
}
 printf("\n");
 
   double time_taken=(double)(end_time-start_time)/ CLOCKS_PER_SEC;
   printf("total time taken to complete is %f seconds\n",time_taken);
   }
