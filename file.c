#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int rand_intervel(int a,int b){
    return rand()%(b-a+1) + a;
}
int main()
{
 FILE *fptr;
 int st,ed;
 float cpu_time;
 st=clock();
 
 fptr=fopen("data5.csv","w");
 int ar[100];
 //fprintf(fptr,"serial number,Integer");
 srand(time(NULL));
 for(int i=1;i<=1000000;i++){
   int b= rand()%100;
   //int b=rand_intervel(1,1000);
     fprintf(fptr," %d\t",b);
    // fscanf(fptr,"1%d",&ar[i]);
  
 }
 ed=clock();
 cpu_time=((double)(ed-st)/CLOCKS_PER_SEC);
 
    printf("The execution time is %f seconds",cpu_time);
    fclose(fptr);
    
    return 0;
}
