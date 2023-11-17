#include<stdio.h>
#include<stdlib.h>
int main(){
int num[100];
FILE *ptr;
ptr=fopen("data3.txt","r");
for(int i=0;i<=100;i++){
    fscanf(ptr,"%d",&num[i]);
    fprintf(ptr,"%d\t",num);
}fclose(ptr);
return 0;
//fprintf();
}
