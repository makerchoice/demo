#include<stdio.h>

#include<iostream>

#include<queue>

using namespace std;

?

//bool select[10];//����һ��bool�����������ж��Ƿ�ѡ�ж�Ӧ��Ʒ��

int bagw=50,bagv,bestvalue,cw,cv;//�����ɳ��������������ɳ��ܼ�ֵ����Ѽ�ֵ����ǰ��������ǰ��ֵ��

float ub;//�Ͻ�;

//queue<thing> bestq;//����һ���ṹ����У����ڴ�����ս����

struct avgvalue{//�ṹ��������ı���뵥λ�����ļ�ֵ��

	int num;

	float avg;

	int value;//��Ӧ��Ʒ��ֵ��

	int weight;//��Ӧ��Ʒ������

}re[10];

?

struct node{//�����㣻

	int cw;

	int cv;

	float ub;

}point[2];//point[0]��ʾ���㣬[1]��ʾ�ҽ�㣻

?

void compare(avgvalue re[10])//������Ʒ��λ�����ļ�ֵ��

{

	int i,j,tmp;

	float t;

	for(i=0;i<=9;i++)

	{

	for(j=i+1;j<=9;j++)

	{

		if(re[i].avg<re[j].avg)

		{

			t=re[i].avg;

			re[i].avg=re[j].avg;

			re[j].avg=t;

			tmp=re[i].value;

			re[i].value=re[j].value;

			re[j].value=tmp;

			tmp=re[i].weight;

			re[i].weight=re[j].weight;

			re[j].weight=tmp;

		 } 

		else

			continue;

	 }

	}

}

int der(avgvalue re1[10])//���޺�����

{

	int i,k,t;//j������ŵ�ǰ���λ�ر�;

	float j;

	cw=0,cv=0;//��ʼ����ǰ�������ֵ��

	j=re[0].avg;

	ub=j*(bagw-cw)+cv;//�Ͻ繫ʽ,�ҵ����ڵ㣻

	for(i=0;i<=8;i++)

	{

	j=re[i+1].avg;

	point[1].cv=cv;

	point[1].cw=cw;

	point[1].ub=j*(bagw-point[1].cw)+point[1].cv;//��������i����Ʒʱ��ǰ��ѻر���

	point[0].cw=re1[i].weight;

	if(cw+point[0].cw<=bagw)//������i����Ʒ�����ص�����£�

	{

	point[0].cv=re1[i].value;

	point[0].ub=j*(bagw-cw-point[0].cw)+point[0].cv+cv;//������i����Ʒʱ��ǰ��ѻر���

?

	if(point[0].ub>point[1].ub)

	{

	ub=point[0].ub;

	cw+=point[0].cw;

	cv+=point[0].cv;

	 }

	else

	ub=point[1].ub;

	}

	else//���������أ�ֱ��ѡ�񲻰����������

	ub=point[1].ub;

	}

	 return cv;

}

?

int main()

{

	int i;

	for(i=0;i<=9;i++)

	{

	cin>>re[i].weight;//����10����Ʒ��������

	}

	for(i=0;i<=9;i++)

	{

	cin>>re[i].value;//����10����Ʒ�ļ�ֵ��

	}

	for(i=0;i<=9;i++)

	{

	re[i].num=i;

	re[i].avg=(float)re[i].value/re[i].weight;

	}

	compare(re);

	bestvalue=der(re);

	cout<<bestvalue<<endl;

	return 0;

}

