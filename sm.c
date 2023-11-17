#include <stdio.h>
#include <string.h>
int main()
{
char s1[20],s2[20];
printf("enter s1:");
gets(s1);
printf("enter s2:");
gets(s2);

int n,m;
n=strlen(s1);
m=strlen(s2);

int f=0,F=0;
for(int i=0;i<n-m+1;i++)
{
for(int j=i;j<i+m;j++)
{
if(s1[j]!=s2[j-i]) 	{
			f=0;
			break;
			}
			else
			{
			f=1;
			}
}
if(f==1) {F=1; break;}
}

if(F==1) printf("\nfound");
else printf("\nnot found");

}
