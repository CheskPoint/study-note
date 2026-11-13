
#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[85];
__int128 p[85];
__int128 dp[85][85];
__int128 ans=0;

// 输出 __int128 类型
void print(__int128 x)
{
    if(x==0)
    {
        cout<<0;
        return;
    }

    string s="";
    while(x>0)
    {
        s+=char(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    cout<<s;
}

int main()
{
    cin>>n>>m;

    // 计算 2 的幂
    p[0]=1;
    for(int i=1;i<=m;i++)
    {
        p[i]=p[i-1]*2;
    }

    // 逐行处理
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>num[j];
        }

        // 区间 DP
        for(int len=1;len<=m;len++)
        {
            int k=m-len+1;

            for(int a=1;a+len-1<=m;a++)
            {
                int b=a+len-1;

                if(len==1)
                {
                    dp[a][b]=num[a]*p[m];
                }
                else
                {
                    dp[a][b]=max(num[a]*p[k]+dp[a+1][b],num[b]*p[k]+dp[a][b-1]);
                }
            }
        }

        ans+=dp[1][m];
    }

    print(ans);

    return 0;
}
