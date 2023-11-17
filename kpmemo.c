#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
 int dp[MAX][MAX];
 int max(int a,int b){
 return (a>b)? a:b;
 }
 int kp(int wt[],int val[],int n, int w){
 dp[n+1][w+1];
     if(n==0 || w==0){
     return 0;
     }
     if(dp[n][w]!=-1){
      return dp[n][w];
      }
     if(wt[n-1]<=w){
       return dp[n][w]=max(val[n-1]+kp(wt,val,n-1,w-wt[n-1]),kp(wt,val,n-1,w));
       }
       else{
       return dp[n][w]= kp(wt,val,n-1,w);
       }
       return dp[n][w];
       }
       
       
    int main(){
    int n,w;
    printf("enter the no.of items in the array\n");
    scanf("%d",&n);
    printf("enter the weight of the bag\n");
    scanf("%d",&w);
    memset(dp,-1,sizeof(dp));
     int wt[n],val[n];
     for (int i=0;i<n;i++){
      printf("enter the weight and value of the item\n");
      scanf("%d %d",&wt[i],&val[i]);
      }
      int max=kp(wt,val,n,w);
      printf("the maximum value of the bag is %d",max);
      return 0;
      }
