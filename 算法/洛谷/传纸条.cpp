
#include<bits/stdc++.h>
using namespace std;

int m,n;
int a[105][105];
int dp[205][105][105];

int main()
{
    cin>>m>>n;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    // 初始化 DP 数组
    for(int k=0;k<=m+n;k++)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[k][i][j]=-1;
            }
        }
    }

    dp[2][1][1]=0;

    // 两张纸条同时向右或向下移动
    for(int k=3;k<=m+n;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x=k-i;
                int y=k-j;

                // 判断位置是否合法
                if(x<1||x>n||y<1||y>n)
                    continue;

                // 经过同一个中间同学
                if(i==j&&k!=m+n)
                    continue;

                // 四种走法
                int t=max({
                    dp[k-1][i][j],
                    dp[k-1][i-1][j],
                    dp[k-1][i][j-1],
                    dp[k-1][i-1][j-1]
                });

                if(t<0)
                    continue;

                dp[k][i][j]=t+a[i][x]+a[j][y];
            }
        }
    }

    cout<<dp[m+n][m][m];

    return 0;
}
