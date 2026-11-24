#include<bits/stdc++.h>
using namespace std;

const long long MOD=1000000007;
int cnt[26];//26个英文字符

//代码中对MOD 取余不改变，都没有MOD大
int main()
{
    int n;
    cin>>n;

    char c;
    //统计字符次数
    for(int i=0;i<n;i++)
    {
        cin>>c;
        cnt[c-'a']++;
    }
    //总排序数
    long long total=1;
    for(int i=1;i<=n;i++)
    {
        total=total*i%MOD;
    }

    //奇数次字符种类
    //当add=0或者1时，代表可以有回文数，odd=2时没有
    int add=0;
    for(int i=0;i<26;i++)
    {
        if(cnt[i]%2==1)
            add++;
    }
    //如果没有回文串,直接输出total
    if(add>1)
    {
        cout<<total;
        return 0;
    }

    //计算回文方案
    long long p=1;
    for(int i=1;i<=n/2;i++)
    {
        p=p * i %MOD;
    }
    //每种字符阶乘之比
    for(int i=0;i<26;i++)
    {
        for(int j=cnt[i]/2 + 1;j<=cnt[i];j++)
        {
            p=p*j%MOD;
        }
    }
    cout<<(total-p+MOD)%MOD;
    return 0;
}
