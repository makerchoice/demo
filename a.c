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
	printf("������Ҫ�������Ŀ(m<1000):");
	scanf("%d",&m);
	printf("������Ҫ�������:");
	srand(time(NULL));
	for(i=0;i<m;i++)
	{
		a[i]=rand()%1000+1; 
	}
	for(i=1;i<m;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("�Ӵ�С����:"); 
	for(i=0;i<m;i++)
	{
		printf("%d ",fun(a,i,m-1));
	}
	
}
