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
		swap(a[i],a[dp]);//交换 
		dfs(dp+1);
		swap(a[i],a[dp]);//回溯回来的时候一定要换回来 
	}
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]=i;//初始化a数组， 
		}
		dfs(1);
	}
}
