#include<bits/stdc++.h>
using namespace std;

int Y(int r[],int n,int m)
{
    int count,i=-1,num=0;//num表示出列的人数，只要还剩>1个人，继续循环,i=-1=>(-1+1)%n=0
    while(num<n-1)//0~n-1
    {
        count=0;//找人前把计数器置为0，用于计数到m
        while(count<m)
        {
            i=(i+1)%n;//把整个数组设置成环形
            if(r[i]!=1)
                count++;
        }
        r[i]=1;//出列
        num++;
        cout<<i+1<<" ";
    }
    for(i=0;i<n;i++)//找出最后一个
    {
        if(r[i]==0)
            return i+1;
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int r[100]={0};//初始化
    Y(r,n,m);
    return 0;
}