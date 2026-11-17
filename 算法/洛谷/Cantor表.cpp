#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int s=1;
    while(n>s*(s+1)/2)//对角线前s个数和
    {
        s++;
    }
    int k=n-s*(s-1)/2;//找出n所在的对角线
    int a,b;//分别代表分子分母

    //Z字形奇数和偶数的方向不同，奇数从下往上，偶数从上往下
    //所以要判断n所在的地方
    //偶数
    if(s%2==0)
    {
        a=k;
        b=s+1-k;
    }
    else//奇数
    {
        a=s+1-k;
        b=k;
    }
    cout<<a<<"/"<<b;
    return 0;
}