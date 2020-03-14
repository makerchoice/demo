#include<stdio.h>				//桶排序 
#define N 1000	 
void main()
{
	int i,m,n,a[N];
	scanf("%d",&n);		//排序数目 
	for(i=0;i<N;i++)
		a[i]=0;			//把各个数组元素赋值为零 
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[m]++;			//把输入的m放入编号为m的桶中，每放一个a[m]++;
	}
	for(i=0;i<N;i++)
	{
		while(a[i]!=0) //把空桶剔除 
		{
			printf("%d ",i); // 输出 
			a[i]--;		//每取出一个元素，a[m]--； 
		}
	} 
	
	
 } 
