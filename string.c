#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 int main(){
 int flag=0;

  char s1[100],s2[20];
  int j;
  printf("enter the string1\n");
  scanf("%s",s1);
  printf("enter the string2\n");
  scanf("%s",s2);
  int m=strlen(s1);
  int n=strlen(s2);
 
 for(int i=0;i<(m-n+1);i++){
   for( j=0;j<n;j++){
      if(s1[i+j]!=s2[j]){
       
           break;
      }
       }
       if(j==n){
       printf("matched\n");
       printf("index %d ",i);
       flag=1;
       break;
      }
       }
       if(!flag){
       printf("not matched");
       }
      return 0;
       }
       

       
