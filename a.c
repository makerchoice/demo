#include<stdio.h>
#define N 1000
#include <stdlib.h>
#include <time.h>
int fun(int a[],int i,int m)
{
	int t;
	if(a[i]<a[m])
		{
			t=a[i];
			a[i]=a[m];
			a[m]=t;
		}
	if(m==i)
		return a[i];
	else
		return fun(a,i,m-1);
	
}
void main()
{
	int a[N],m,i,j,t;
	printf("请输入要排序的数目(m<1000):");
	scanf("%d",&m);
	printf("请输入要排序的数:");
	srand(time(NULL));
	for(i=0;i<m;i++)
	{
		a[i]=rand()%1000+1; 
	}
	for(i=1;i<m;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("从大到小排序:"); 
	for(i=0;i<m;i++)
	{
		printf("%d ",fun(a,i,m-1));
	}
	
}
