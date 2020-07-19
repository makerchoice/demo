// 【动态规划】0-1背包问题
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;		// 物品个数
int c;		// 背包容量
int* w;		// 每个物品的重量
int* v;		// 每个物品的价值

int* x;		// 物品是否被放入背包
int** m;	// 最大价值

void Data_input();
void Knapsack();
void Traceback();

int main()
{
	cout << "【动态规划】0-1背包问题\n\n";

	// 输入
	Data_input();

	// 自底向上的计算，填表，
	Knapsack();
	Traceback();

	// 输出
	cout << "\n可选的最大价值是：" << m[1][c] << endl;
	cout << "所选的物品情况是：";
	for (int i = 1;i <= n;i++)
		cout << x[i] << " ";
	
	cout << endl;
	return 0;
}

// 用户输入
void Data_input()
{
	cout << "请输入物品个数：";
	cin >> n;
	cout << "请输入背包容量：";
	cin >> c;

	w = new int[n + 1];
	v = new int[n + 1];
	x = new int[n + 1];
	m = new int* [n + 1];
	for (int i = 0;i <= n;i++)
	{
		m[i] = new int[c + 1];
		memset(m[i], 0, sizeof(int) * (c + 1)); // 将表m所有元素设为0
	}

	cout << "请输入物品的重量和价值：\n";
	for (int i = 1;i <= n;i++)
	{
		cout << "#" << i << ":";
		cin >> w[i];
		cin >> v[i];
	}
}

// 最大价值表,填表
void Knapsack()
{
	int jMax = min(w[n] - 1, c);	// 避免存在单个重量超出背包容量的物品使数组m越界
	// 以下两个for循环是最大价值表m的最后一行
	for (int j = 0;j <= jMax;j++)
		m[n][j] = 0;
	for (int j = w[n];j <= c;j++)
		m[n][j] = v[n];
	// 以下是表m最后一行以上的部分
	for (int i = n - 1;i > 1;i--)
	{
		jMax = min(w[i] - 1, c);
		for (int j = 0;j <= jMax;j++)
			// 背包容量<物品重量，即装不下；将m[i+1][j]（下一行同列）的值赋给m[i][j]
			m[i][j] = m[i + 1][j];
		for (int j = w[i];j <= c;j++)
			// 背包容量>=物品重量，即可以装下；
			//		放：m[i][j]=m[i + 1][j - w[i]] + v[i]
			//		不放：m[i][j]=m[i + 1][j]
			// 哪个价值大，就采取哪种方式
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
}

// 将最优解存入数组
void Traceback()
{
	int cTemp = c;	// 临时背包容量
	for (int i = 1;i < n;i++)
	{
		if (m[i][cTemp] == m[i + 1][cTemp])
			x[i] = 0;	// 价值相等，说明没有放入这个物品，0
		else
		{
			x[i] = 1;	// 价值不相等，说明放入了这个物品，1
			cTemp -= w[i];	// 放入了一个物品，背包剩余容量为原容量-物品重量
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;	// 最后一个物品，非0为true放入，0为false不放入
}

