#include<bits/stdc++.h>
using namespace std;

//可以把整个总人数表示为Aa+Bk=m
int a,n,m,x;
int main()
{
    cin>>a>>n>>m>>x;//输入
    if(x==n)
    {
        cout<<0;
        return 0;
    }

    auto f = [&](int k)
    {
        vector<long long> up(n+1,0);//上车人数，n+1数组长度，初始元素初始化为0
        vector<long long> sum(n+1,0);//总人数，n+1数组长度，初始元素初始化为0
        up[1]=a;//初始上车人数a
        sum[1]=a;//初始人数
        if(n>=3)
        {
            up[2]=k;//第二站下车人数k
            sum[2]=a;//第二站总人数
        }
        for(int i=3;i<=n;i++)
        {
            up[i]=up[i-1]+up[i-2];//上车的人数都是前两站上车人数之和
            sum[i]=sum[i-1]+up[i]-up[i-1];//下车人数等于上一站上车人数
            //uo[1-1]-up[i-2]等于总增加数
        }
        return sum;
    };
    vector <long long> to0=f(0);//假设第二站上车人数0
    vector <long long> to1=f(1);//假设第二站上车人数为1

    //Aa+Bk=m，求出系数b
    long long b=to1[n-1]-to0[n-1];
    if(b==0)
    {
        cout<<to0[x];
        return 0;
    }
     //最后全部下车，总人数减去上一站的总人数
    long long k=(m-to0[n-1])/b;//求出上车人数k
    cout<<to0[x]+(to1[x]-to0[x])*k;

    return 0;
}