/*7.谣言传播 有n个人，每个人都拥有不同的谣言。通过发电子信息，他们相互想共享所有的谣言。
假定发送者会在信息中包含他已知的所有谣言，而且一条信息只有一个收信人。
设计一个贪心算法，保证再给个人都能获得所有谣言的条件下，是发送的信息数最小。

, 2, …, n，按照1发信给2, 2发信给3, 3发信给4，…，
n-1发信给n的方式发送谣言，该贪心算法基于每次发信都使得当前收信人掌握的谣言更多，
最后由n将所有谣言发送给其他n-1个人。
发送信息总数为2n-2，这是最小的发信息数。
因为每增加一个人，至少需要增加两次发送信息，当n=2是，
发送信息数为2，归纳法可证明2n-2为最小发信息数
*/


#include <iostream>
using namespace std;

const int maxnum = 100;
const int maxint = 999999;



void initation(int dist[maxnum][maxnum], int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = maxint;
	}
	}
}
void Dijkstra(int n, int v, int dist[maxnum][maxnum], int *prev, int c[maxnum][maxnum])
{
	bool s[maxnum];	// 判断是否已存入该点到S集合中
	for (int i = 1; i <= n; ++i)
	{
		dist[v][i] = c[v][i];
		s[i] = 0; // 初始都未用过该点
		if (dist[v][i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v][v] = 0;
	s[v] = 1;

	// 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
	// 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
	for (int i = 2; i <= n; ++i)
	{
		int tmp = maxint;
		int u = v;
		// 找出当前未使用的点j的dist[j]最小值
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[v][j]<tmp)
			{
				u = j;	// u保存当前邻接点中距离最小的点的号码
				tmp = dist[v][j];
			}
		s[u] = 1;	 // 表示u点已存入S集合中

	 // 更新dist
	for (int j = 1; j <= n; ++j)
		if ((!s[j]) && c[u][j]<maxint)
		{
			int newdist = dist[v][u] + c[u][j];
			if (newdist < dist[v][j])
			{
				dist[v][j] = newdist;
				prev[j] = u;
			}
		}
	}
}

void searchPath(int *prev, int v, int u)
{
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v)
	{
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	for (int i = tot; i >= 1; --i)
		if (i != 1)
			cout << que[i] << " -> ";
		else
			cout << que[i] << endl;
}

void YuanDian(int dist[maxnum][maxnum], int n, int m[maxnum]) {
	for (int i = 1; i <= n; i++) {
		m[i] = dist[i][1];
			for (int j = 1; j <= n; j++) {
				if (m[i] < dist[i][j] && i != j) {
					m[i] = dist[i][j];
			}
		}		
	}
	int min = m[1];
	int a = 0;
	for (int k = 1; k <= n; k++) {
		if (min > m[k]) {
			min = m[k];
			a = k;
	}
}
cout << "应从" << a << "开始" << "时间最短为" << min << endl;
}

int main()
{
	// 各数组都从下标1开始
	int dist[maxnum][maxnum];	 // 表示当前点到源点的最短路径长度
	int prev[maxnum];	 // 记录当前点的前一个结点
	int c[maxnum][maxnum];	 // 记录图的两点间路径长度
	int n, line;	 // 图的结点数和路径数
	int m[maxnum];
	// 输入结点数
	cin >> n;
	// 输入路径数
	cin >> line;
	int p, q, len;	 // 输入p, q两点及其路径长度

	// 初始化c[][]为maxint
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			c[i][j] = maxint;

	for (int i = 1; i <= line; ++i)
	{
	cin >> p >> q >> len;
	c[p][q] = len;
	}


	initation(dist, n);
	for (int i = 1; i <= n; i++) {
		Dijkstra(n, i, dist, prev, c);
	}

	YuanDian(dist, n, m);
	system("pause");
	//searchPath(prev, 1, k);
}


