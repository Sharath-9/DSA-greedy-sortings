#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define sqrt
 struct point {
 double y, x;
 };
 
 
 double dis(struct point a,struct point b){
      double dx=a.x-b.x;
     double dy =a.y-b.y;
  return  sqrt(dx*dx+dy*dy);

 }
 double brut(struct point* p,int n,struct point* n1, struct point* n2){
 double dmin=INFINITY;
 for(int i=0;i<n-1;i++){
 for(int j=i+1;j<n;j++){
 double dist = dis(p[i],p[j]);
   if(dist<dmin){
      dmin=dist;
       *n1=p[i];
       *n2=p[j];
      }
      }
      }
      return dmin;
      }
      
      
      int main(){
   int n;
   printf("enter the no.of pairs of points u want");
   scanf("%d",&n);
   struct point *c=malloc(n*sizeof(struct point));
  // c[n];
  if(c==NULL){
  printf("Unable to allocate the memmory\n");
  exit(1);
  }
   printf("Enter the points\n");
   for(int i=0;i<n;i++)
   scanf("%lf %lf",&c[i].x,&c[i].y);
    
   struct point n1,n2;
   double min_dis=brut(c,n,&n1,&n2);
   printf("The closest pair of points is (%.1f,%.1f) & (%.1f,%.1f)\n",n1.x,n1.y,n2.x,n2.y);
   printf("minimum distance is %.1f\n",min_dis);
   }
   
   
