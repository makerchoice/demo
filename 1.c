#include<stdio.h>				//Ͱ���� 
#define N 1000	 
void main()
{
	int i,m,n,a[N];
	scanf("%d",&n);		//������Ŀ 
	for(i=0;i<N;i++)
		a[i]=0;			//�Ѹ�������Ԫ�ظ�ֵΪ�� 
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[m]++;			//�������m������Ϊm��Ͱ�У�ÿ��һ��a[m]++;
	}
	for(i=0;i<N;i++)
	{
		while(a[i]!=0) //�ѿ�Ͱ�޳� 
		{
			printf("%d ",i); // ��� 
			a[i]--;		//ÿȡ��һ��Ԫ�أ�a[m]--�� 
		}
	} 
	
	
 } 
