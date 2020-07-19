#pragma GCC optimize(3,"Ofast","inline")
#pragma G++ optimize(3)
#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef queue<int> q_i;
typedef queue<string> q_s;
typedef queue<double> q_d;
typedef queue<ll> q_ll;
typedef queue<char> q_c;
typedef priority_queue<int> pq_i;
typedef priority_queue<string> pq_s;
typedef priority_queue<double> pq_d;
typedef priority_queue<ll> pq_ll;
typedef stack<int> s_i;
typedef stack<string> s_s;
typedef stack<double> s_d;
typedef stack<ll> s_ll;
typedef stack<char> s_c;
typedef map<ll,ll> m_ll_ll;
typedef map<int,ll> m_i_ll;
typedef map<string,ll> m_s_ll;
typedef map<char,int> m_c_i;
typedef map<char,ll> m_c_ll;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define per(i,l,r) for(ll i=r;i>=l;i--)
#define eif else if
#define N 3005
#define mm(dp) memset(dp,0,sizeof(dp))
#define mm1(dp) memset(dp,-1,sizeof(dp))
#define mm2(dp) memset(dp,0x3f,sizeof(dp))
#define IT set<int>::iterator
#define fs(n) fixed<< setprecision(n)
#define inf 0x3f3f3f3f
const double e=2.71828182845;
const double pi = acos(-1.0);
map<char,int>mapp;
map<char,string>mapp1;
typedef struct
{
    string s1;
    int num;
}STU;
typedef struct
{
    string s1,s0;
    int num;
}STU1;
bool cmp(STU x,STU y)
{
    return x.num>y.num;
}
typedef struct node
{
    string data;
    struct node *left,*right;
}HuffmanTreeNode,*PtrHuffman;
class Haffman
{
    public:
    PtrHuffman head=NULL;
    PtrHuffman p[100005];
    void create1(int nm,STU *stu)
    {
        int u=0;
        rep(i,1,nm)
        {
            PtrHuffman t=new HuffmanTreeNode;
            t->data = stu[i].s1;
            t->left = t->right = NULL;
            p[i]= t;
        }
        rep(i,1,nm-1)
        {
            int fi=inf,se=inf;
            int fi1=0,se1=0;
            rep(j,1,nm+u)
            {
                if(stu[j].num>0&&stu[j].num<fi)
                {
                    fi=stu[j].num;
                    fi1=j;
                }
            }
            rep(j,1,nm+u)
            {
                if(stu[j].num>0&&stu[j].num<se&&j!=fi1)
                {
                    se=stu[j].num;
                    se1=j;
                }
            }
            PtrHuffman q=new HuffmanTreeNode;
            q->data=p[fi1]->data+p[se1]->data;
            q->left=p[fi1];
            q->right=p[se1];
            u++;
            stu[nm+u].s1=stu[fi1].s1+stu[se1].s1;
            stu[nm+u].num=stu[fi1].num+stu[se1].num;
            p[nm+u]=q;
            stu[fi1].num=-1;
            stu[se1].num=-1;
            head=q;
        }
    }
    void bianli(struct node *t1,int u)
    {
        if(t1==NULL)
            return;
        if(u==0)
            cout<<t1->data<<endl;
        else
        {
            cout<<u<<" ";
            cout<<t1->data<<endl;
        }
        bianli(t1->left,u+1);
        bianli(t1->right,u+1);
    }

    void bianli1(struct node *t1,char ch,string str)
    {
        if(t1==NULL)
            return;
        string s1="";
        s1+=ch;
        string ss=t1->data;
        if(ss==s1)
        {
            mapp1[ch]=str;
            return;
        }
        else
        {
            string s=t1->data;
            int len=s.size();
            int flag=0;
            rep(i,0,len)
            {
                if(s[i]==ch)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return;
            else
            {
                bianli1(t1->left,ch,str+"0");
                bianli1(t1->right,ch,str+"1");
            }
        }
    }
    STU1 bianli2(struct node *t1,string str)
    {
        if(t1->data.size()==1)
        {
            STU1 stu;
            stu.s1=t1->data;
            int len=str.size();
            stu.s0=str;
            return stu;
        }
        char ch=str[0];
        int len=str.size();
        str=str.substr(1,len-1);
        if(ch=='0')
        {
            return bianli2(t1->left,str);
        }
        if(ch=='1')
        {
            return bianli2(t1->right,str);
        }
    }
};
int len;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    Haffman ha;
    char str[10005];
    int uu=0;
    while(1)
    {
        char ch;
        cin>>ch;
        if(ch=='X')
            break;
        eif(ch=='I')
        {
            getchar();
            char c;
            scanf("%c",&c);
            int i=0;
            while(c!='\n')
            {
                str[i]=c;
                i++;
                scanf("%c",&c);
            }
            len=i;
            string ss="";
            rep(i,0,len-1)
            {
                if(mapp[str[i]]==0)
                {
                    mapp[str[i]]=1;
                    ss+=str[i];
                }
                eif(mapp[str[i]]!=0)
                {
                    mapp[str[i]]++;
                }
            }
            int len1=ss.size();
            STU stu[10005];
            rep(i,0,len1-1)
            {
                string s0="";
                char c=ss[i];
                s0+=c;
                stu[i+1].s1=s0;
                stu[i+1].num=mapp[c];
            }
            ha.create1(len1,stu);
            cout<<"Huffman code established!"<<endl;
            uu=1;
        }
        eif(ch=='C')
        {
            if(uu==0)
            {
                cout<<"Huffman code does not exist!"<<endl;
            }
            else{
            rep(i,0,len-1)
            {
                char cc=str[i];
                ha.bianli1(ha.head,cc,"");
                cout<<mapp1[str[i]];
            }
            cout<<endl;
        }}
        eif(ch=='D')
        {
            if(uu==0)
            {
                cout<<"Huffman code does not exist!"<<endl;
            }
            else{

            string s2;
            cin>>s2;
            while(1)
            {
                if(s2=="")
                    break;
                STU1 huan=ha.bianli2(ha.head,s2);
                cout<<huan.s1;
                s2=huan.s0;
            }
            cout<<endl;
        }}
    }
    return 0;
} 
