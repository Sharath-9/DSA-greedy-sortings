#include<stdio.h>
void swap(int *a, int *b){
int temp=*a;
*a=*b;
*b=temp;
}
void selectsort(int C[], int n){
int i,j,k;
for(i=0;i<(n-1);i++){
k=i;
for(j=i+1;j<n;j++){
if(C[j]<C[k])
k=j;
}
if(k!=i)
swap(&C[i],&C[k]);
}printf("Sorted array\n");
for( i=0;i<n;i++){
printf("%d ",C[i]);
}printf("NULL");
}

int main(){
int A[]={3,7,9,10,6,12,4,11,2,8},n=10,i;
int B[]={1,70,21,666,71,9,3,75,88,11},x=10;
int C[]={1,70,21,666,71,9,3,75,88,11},y=10;
/*bubblesort(A,n);
printf("Bubblesort\n");
for( int i=0;i<10;i++){
printf("%d ",A[i]);
}
printf("\ninsertionsort\n");
insertsort(B,x);
for( int i=0;i<10;i++){
printf("%d ",B[i]);
}*/
selectsort(C,y);

}
