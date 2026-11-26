#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V, n;
    cin >> V >> n;

    vector<int> a(n + 1);
    vector<int> dp(V + 1, 0);

    // 输入每个物品的体积
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // 遍历每个物品
    for(int i = 1; i <= n; i++)
    {
        // 从大到小遍历箱子容量
        for(int j = V; j >= a[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }

    // 输出最小剩余空间
    cout << V - dp[V];

    return 0;
}