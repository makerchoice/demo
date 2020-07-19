/*7.ҥ�Դ��� ��n���ˣ�ÿ���˶�ӵ�в�ͬ��ҥ�ԡ�ͨ����������Ϣ�������໥�빲�����е�ҥ�ԡ�
�ٶ������߻�����Ϣ�а�������֪������ҥ�ԣ�����һ����Ϣֻ��һ�������ˡ�
���һ��̰���㷨����֤�ٸ����˶��ܻ������ҥ�Ե������£��Ƿ��͵���Ϣ����С��

, 2, ��, n������1���Ÿ�2, 2���Ÿ�3, 3���Ÿ�4������
n-1���Ÿ�n�ķ�ʽ����ҥ�ԣ���̰���㷨����ÿ�η��Ŷ�ʹ�õ�ǰ���������յ�ҥ�Ը��࣬
�����n������ҥ�Է��͸�����n-1���ˡ�
������Ϣ����Ϊ2n-2��������С�ķ���Ϣ����
��Ϊÿ����һ���ˣ�������Ҫ�������η�����Ϣ����n=2�ǣ�
������Ϣ��Ϊ2�����ɷ���֤��2n-2Ϊ��С����Ϣ��
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
	bool s[maxnum];	// �ж��Ƿ��Ѵ���õ㵽S������
	for (int i = 1; i <= n; ++i)
	{
		dist[v][i] = c[v][i];
		s[i] = 0; // ��ʼ��δ�ù��õ�
		if (dist[v][i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v][v] = 0;
	s[v] = 1;

	// ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
	// һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
	for (int i = 2; i <= n; ++i)
	{
		int tmp = maxint;
		int u = v;
		// �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[v][j]<tmp)
			{
				u = j;	// u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
				tmp = dist[v][j];
			}
		s[u] = 1;	 // ��ʾu���Ѵ���S������

	 // ����dist
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
cout << "Ӧ��" << a << "��ʼ" << "ʱ�����Ϊ" << min << endl;
}

int main()
{
	// �����鶼���±�1��ʼ
	int dist[maxnum][maxnum];	 // ��ʾ��ǰ�㵽Դ������·������
	int prev[maxnum];	 // ��¼��ǰ���ǰһ�����
	int c[maxnum][maxnum];	 // ��¼ͼ�������·������
	int n, line;	 // ͼ�Ľ������·����
	int m[maxnum];
	// ��������
	cin >> n;
	// ����·����
	cin >> line;
	int p, q, len;	 // ����p, q���㼰��·������

	// ��ʼ��c[][]Ϊmaxint
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


