
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, N, M;
    cin >> T >> N >> M;
    int p[105][105];
    // 读入每天每种纪念品的价格
    for(int i = 1; i <= T; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> p[i][j];
        }
    }

    // 逐天进行交易
    for(int i = 1; i < T; i++)
    {
        vector<int> dp(M + 1);

        // 初始化：不买任何纪念品
        for(int j = 0; j <= M; j++)
        {
            dp[j] = j;
        }

        // 枚举每一种纪念品
        for(int j = 1; j <= N; j++)
        {
            int cost = p[i][j];       // 今天买入的价格
            int value = p[i + 1][j];  // 明天卖出的价格

            // 完全背包：从小到大枚举
            for(int k = cost; k <= M; k++)
            {
                dp[k] = max(dp[k], dp[k - cost] + value);
            }
        }

        // 更新金币数量
        M = dp[M];
    }

    cout << M;

    return 0;
}
