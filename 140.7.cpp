#include
#include
#include
using namespace std; //���������ͷ�ļ�
void main()
{
	void sort1(int *);//ð�ݷ�����
	void sort2(int *);//��������
	int i;
	tint a[1000];
	tsrand(time(0)); //���������
	for(i=0;i<1000;i++)
	{
	
	a[i]=1+rand()%1000;\t//�������ʹ�÷���
	}
	int q;
	cout<<"1--ð�ݷ�"<<"2--��������";
	cout<<"��ѡ��:";
	cin>>q;
	cout<<"�����Ľ��Ϊ��";
	switch(q)
	{
		case 1:
			sort1(a);
		break;
		case 2:
			sort2(a);
		break;
	}
}
void sort1(int *a)
{
	int i,j,temp,t=1;
	for(i=1;i<1000;i++)
	for(j=1000-1;j>=i;j--)
		if(a[j]<a[j-1])
		{
			temp=a[j];
			a[j]=a[j-1];
			a[j-1]=temp;
		} //ð�ݲ���
	for(i=0;i<1000;i++)
	{
	cout<<setw(5)<<a[i];//Ϊ��ʹ��������ݶ���
	t++;
	if(t%16==0) //ÿ���15��������
	{
	cout<<endl;
	t=1;
	}
}
}
void sort2(int *a)
{
	int i,j,k,t,m=1;
	for(i=0;i<1000-1;i++)
	{
		k=i; //�ѵ�һ�������±긳��k
		for(j=i+1;j<1000;j++)//�Ƚϳ���С�ģ����˵�һ������
		{
			if (a[j]<a[k])
				k=j; //�ѱȵ�һ����С�������±����˸���k
				t=a[i];a[i]=a[k];a[k]=t;//����С�������һ��������
		}
	}
	for(i=0;i<1000;i++)
	{
		cout<<setw(5)<<a[i];//Ϊ��ʹ��������ݶ���
		m++;
		if(t%16==0) //ÿ���15��������
		{
			cout<<endl;
			m=1;
		}
	}

}

��ϣ������д������д��
#include
void shsort(int s[],int n)
{
int i,j,d;
d=n/2; //ȷ���̶�����ֵ
while(d>=1)
{
for (i=d+1;i<=n;i++) //�����±��d+1��ʼ����ֱ�Ӳ�������
{
s[0]=s[i]; //���ü�����
j=i-d; //ȷ��Ҫ���бȽϵ�Ԫ�ص����ұ�λ��
while((j>0)&& (s[0]<s[j]))
{
s[j+d]=s[j]; //��������
j=j-d; //������d��λ��
}
s[j+d]=s[0]; //��ȷ����λ�ò�����s[i]
}
d=d/2; //�������ԭ����һ��
}
}
void main()
{
int i,a[11];
printf ("please input numbers:
");
for (i=1;i<=10;i++)
scanf("%d",&a[i]);
shsort(a,10);
printf ("the sorted numbers is :
");
for (i=1;i<=10;i++)
printf("%5d",a[i]);

}

