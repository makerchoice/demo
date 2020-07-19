#include
#include
#include
using namespace std; //随机数函数头文件
void main()
{
	void sort1(int *);//冒泡法函数
	void sort2(int *);//快速排序法
	int i;
	tint a[1000];
	tsrand(time(0)); //调用随机数
	for(i=0;i<1000;i++)
	{
	
	a[i]=1+rand()%1000;\t//随机数的使用方法
	}
	int q;
	cout<<"1--冒泡法"<<"2--快速排序法";
	cout<<"请选择:";
	cin>>q;
	cout<<"排序后的结果为：";
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
		} //冒泡部分
	for(i=0;i<1000;i++)
	{
	cout<<setw(5)<<a[i];//为了使输入的数据对齐
	t++;
	if(t%16==0) //每输出15个数换行
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
		k=i; //把第一个数的下标赋给k
		for(j=i+1;j<1000;j++)//比较出最小的（出了第一个数）
		{
			if (a[j]<a[k])
				k=j; //把比第一个数小的数的下标依此赋给k
				t=a[i];a[i]=a[k];a[k]=t;//把最小的数与第一个数交换
		}
	}
	for(i=0;i<1000;i++)
	{
		cout<<setw(5)<<a[i];//为了使输入的数据对齐
		m++;
		if(t%16==0) //每输出15个数换行
		{
			cout<<endl;
			m=1;
		}
	}

}

用希尔排序法写，具体写法
#include
void shsort(int s[],int n)
{
int i,j,d;
d=n/2; //确定固定增量值
while(d>=1)
{
for (i=d+1;i<=n;i++) //数组下标从d+1开始进行直接插入排序
{
s[0]=s[i]; //设置监视哨
j=i-d; //确定要进行比较的元素的最右边位置
while((j>0)&& (s[0]<s[j]))
{
s[j+d]=s[j]; //数据右移
j=j-d; //向左移d个位置
}
s[j+d]=s[0]; //在确定的位置插入是s[i]
}
d=d/2; //增量变成原来的一半
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

