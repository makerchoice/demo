#include<iostream>
using namespace std;
int n,a[100];
void dfs(int dp)
{
	if(dp>n)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=dp;i<=n;i++)
	{
		swap(a[i],a[dp]);//���� 
		dfs(dp+1);
		swap(a[i],a[dp]);//���ݻ�����ʱ��һ��Ҫ������ 
	}
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=i;//��ʼ��a���飬 
		}
		dfs(1);
	}
}
