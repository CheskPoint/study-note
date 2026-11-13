#include <bits/stdc++.h>
using namespace std;

int n,m;
int num[85];
int p[85];
int dp[85][85];

int main()
{
    cin>>n>>m;

    // 预处理 2 的幂
    p[0]=1;

    for(int i=1;i<=m;i++)
    {
        p[i]=p[i-1]*2;
    }

    int ans=0;

    // 逐行处理矩阵
    for(int row=1;row<=n;row++)
    {
        for(int i=1;i<=m;i++)
        {
            cin>>num[i];
        }

        // 区间 DP
        for(int len=1;len<=m;len++)
        {
            int k=m-len+1;

            for(int a=1;a+len-1<=m;a++)
            {
                int b=a+len-1;

                // 只剩一个数字
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

        // 累加当前行的最大得分
        ans+=dp[1][m];
    }

    cout<<ans<<endl;

    return 0;
}
