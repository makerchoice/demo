#include<stdio.h>//不递归 
#define N 1000
void main()
{
	int a[N],m,i,j,t;
	printf("请输入要排序的数目(m<1000):");
	scanf("%d",&m);
	printf("请输入要排序的数:");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		for(j=m;j>=i;j--)
			if(a[j]>a[i])
			{
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		printf("%d ",a[i]);
	}
}
