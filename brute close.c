#include<stdlib.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
 float x;
 float y;
   
 }point;
 float dis( point p1, point p2){
 float dx=p1->x-p2->x;
 float dy=p1->y-p2->y;
 float d=(sqrt(dx*dx+dy*dy));
 return d;
 }
 int  closest( point p[],int n, point *n1, point *n2){
 float dmin=+99999999;
 for(int i=0;i<n-1;i++){
 for(int j=i+1;j<n;j++){
 double dist=dis(point[i],point[j]);
   if(dist<dmin){
      dmin=dist;
      *n1=point[i];
      *n2=point[j];
      }
      }
      }
      printf("the minimum distance is %d\n",dmin);
      }
      
      
      int main(){
  struct point c[100];
   int n;
   printf("Enter the no.of points\n");
   for(int i=0;i<n;i++){
   scanf("%d%d",&c[i].x,&c[i].y);
   }
   dis(c[i].x,c[i].y);
   closest(p,n,&n1,&n2);
   
