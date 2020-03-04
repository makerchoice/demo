#include<stdio.h>//递归冒泡排序(从小到大） 
#define N 1000
#include <stdlib.h>
#include <time.h>
int count=0;//比较次数 
int fun(int a[],int i,int m)//递归函数 
{
	int t;	
	if(m==i)
		return a[i];
	else
	{ 	
		if(a[i]>a[m]) 
		{
				t=a[i];
				a[i]=a[m];
				a[m]=t;
		}
		count++;
		return fun(a,i,m-1);//i不变，m--；实现 m-i-1次a[i]和a[m]比较 
	}	
	
}
void main()
{
	int a[N],m,i,j,t;
	printf("请输入要排序的数目(m<1000):");
	scanf("%d",&m);
	srand(time(NULL));// 设置一个随机种子
	for(i=0;i<m;i++)
	{
		a[i]=rand()%1000+1; //随机产生 1~1000的数 赋予a[i] 
	}
	for(i=0;i<m;i++)
		printf("%d ",a[i]);//排序前 
	printf("\n");
	printf("从小到大排序:"); 
	for(i=0;i<m;i++)
	{
		printf("%d ",fun(a,i,m-1));//排序后 
	}
	printf("一共比较了：%d次",count);
	
}
