// ����̬�滮��0-1��������
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;		// ��Ʒ����
int c;		// ��������
int* w;		// ÿ����Ʒ������
int* v;		// ÿ����Ʒ�ļ�ֵ

int* x;		// ��Ʒ�Ƿ񱻷��뱳��
int** m;	// ����ֵ

void Data_input();
void Knapsack();
void Traceback();

int main()
{
	cout << "����̬�滮��0-1��������\n\n";

	// ����
	Data_input();

	// �Ե����ϵļ��㣬���
	Knapsack();
	Traceback();

	// ���
	cout << "\n��ѡ������ֵ�ǣ�" << m[1][c] << endl;
	cout << "��ѡ����Ʒ����ǣ�";
	for (int i = 1;i <= n;i++)
		cout << x[i] << " ";
	
	cout << endl;
	return 0;
}

// �û�����
void Data_input()
{
	cout << "��������Ʒ������";
	cin >> n;
	cout << "�����뱳��������";
	cin >> c;

	w = new int[n + 1];
	v = new int[n + 1];
	x = new int[n + 1];
	m = new int* [n + 1];
	for (int i = 0;i <= n;i++)
	{
		m[i] = new int[c + 1];
		memset(m[i], 0, sizeof(int) * (c + 1)); // ����m����Ԫ����Ϊ0
	}

	cout << "��������Ʒ�������ͼ�ֵ��\n";
	for (int i = 1;i <= n;i++)
	{
		cout << "#" << i << ":";
		cin >> w[i];
		cin >> v[i];
	}
}

// ����ֵ��,���
void Knapsack()
{
	int jMax = min(w[n] - 1, c);	// ������ڵ�����������������������Ʒʹ����mԽ��
	// ��������forѭ��������ֵ��m�����һ��
	for (int j = 0;j <= jMax;j++)
		m[n][j] = 0;
	for (int j = w[n];j <= c;j++)
		m[n][j] = v[n];
	// �����Ǳ�m���һ�����ϵĲ���
	for (int i = n - 1;i > 1;i--)
	{
		jMax = min(w[i] - 1, c);
		for (int j = 0;j <= jMax;j++)
			// ��������<��Ʒ��������װ���£���m[i+1][j]����һ��ͬ�У���ֵ����m[i][j]
			m[i][j] = m[i + 1][j];
		for (int j = w[i];j <= c;j++)
			// ��������>=��Ʒ������������װ�£�
			//		�ţ�m[i][j]=m[i + 1][j - w[i]] + v[i]
			//		���ţ�m[i][j]=m[i + 1][j]
			// �ĸ���ֵ�󣬾Ͳ�ȡ���ַ�ʽ
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);
}

// �����Ž��������
void Traceback()
{
	int cTemp = c;	// ��ʱ��������
	for (int i = 1;i < n;i++)
	{
		if (m[i][cTemp] == m[i + 1][cTemp])
			x[i] = 0;	// ��ֵ��ȣ�˵��û�з��������Ʒ��0
		else
		{
			x[i] = 1;	// ��ֵ����ȣ�˵�������������Ʒ��1
			cTemp -= w[i];	// ������һ����Ʒ������ʣ������Ϊԭ����-��Ʒ����
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;	// ���һ����Ʒ����0Ϊtrue���룬0Ϊfalse������
}

