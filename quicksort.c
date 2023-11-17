#include<stdio.h>
#include<stdlib.h>
void swap( int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
  }
  
 int partition(int a[],int l, int h){
 int pivot=a[h];
 int i=l-1; int j=h+1;
 while(1){
 do{
 i++;
 }
  while(a[i]<pivot);
  do{j--;}
  while(a[j]>pivot);
  if(i >= j){
    return j;  
  }
  swap(&a[i],&a[j]);
  
  }
  }
 int quicksort(int a[],int l,int h) {
   if(l<h){
   int j=partition(a,l,h);
   quicksort(a,l,j);
   quicksort(a,j+1,h);
   }
   }
   int main(){
    int a[]={3,9,11,4,1,7,10},n=7,i;
       quicksort(a,0,n-1);
       for(i=0;i<7;i++){
       printf("%d ",a[i]);
       }
       printf("\n");
       }
       
    
  
