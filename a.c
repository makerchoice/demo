#include<stdio.h>//�ݹ�ð������(��С���� 
#define N 1000
#include <stdlib.h>
#include <time.h>
int count=0;//�Ƚϴ��� 
int fun(int a[],int i,int m)//�ݹ麯�� 
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
		return fun(a,i,m-1);//i���䣬m--��ʵ�� m-i-1��a[i]��a[m]�Ƚ� 
	}	
	
}
void main()
{
	int a[N],m,i,j,t;
	printf("������Ҫ�������Ŀ(m<1000):");
	scanf("%d",&m);
	srand(time(NULL));// ����һ���������
	for(i=0;i<m;i++)
	{
		a[i]=rand()%1000+1; //������� 1~1000���� ����a[i] 
	}
	for(i=0;i<m;i++)
		printf("%d ",a[i]);//����ǰ 
	printf("\n");
	printf("��С��������:"); 
	for(i=0;i<m;i++)
	{
		printf("%d ",fun(a,i,m-1));//����� 
	}
	printf("һ���Ƚ��ˣ�%d��",count);
	
}
