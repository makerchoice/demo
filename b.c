#include<stdio.h>//���ݹ� 
#define N 1000
void main()
{
	int a[N],m,i,j,t;
	printf("������Ҫ�������Ŀ(m<1000):");
	scanf("%d",&m);
	printf("������Ҫ�������:");
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
