#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
 float x;
 float y;

 }point;
 
 
 double dis( point *p1, point *p2){
      float dx=p1->x-p2->x;
     float dy=p1->y-p2->y;
    float d=(sqrt(dx*dx+dy*dy));
 return d;
 }
 int  closest(struct point p[],int n,struct point *n1, struct point *n2){
 float dmin=+99999999;
 for(int i=0;i<n-1;i++){
 for(int j=i+1;j<n;j++){
 double dist = dis(p[i],p[j]);
   if(dist<dmin){
      dmin=dist;
      int n1=p[i];
      int n2=p[j];
      }
      }
      }
      return dmin;
      }
      
      
      int main(){
   int n;
   struct point *c[n];
   struct point *c=malloc(n*sizeof(point));
   
   printf("Enter the no.of points\n");
   for(int i=0;i<n;i++)
   scanf("%d%d",&c[i]->x,&c[i]->y);
    
   struct point *n1,*n2;
   double min_dis=closest(c,n,&n1,&n2);
   printf("minimum distance is %.2lf\n",min_dist);
   }
   
   
