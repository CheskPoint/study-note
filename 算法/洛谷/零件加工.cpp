
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    // 建立无向图
    vector<vector<int>> g(n + 1);

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    // dist[0][u]：偶数步到达 u 的最短距离
    // dist[1][u]：奇数步到达 u 的最短距离
    vector<vector<int>> dist(2, vector<int>(n + 1, -1));

    queue<pair<int, int>> que;

    // 从 1 号工人开始 BFS
    dist[0][1] = 0;
    que.push({1, 0});

    while(!que.empty())
    {
        int u = que.front().first;
        int p = que.front().second;
        que.pop();

        for(int v : g[u])
        {
            int np = p ^ 1;

            if(dist[np][v] == -1)
            {
                dist[np][v] = dist[p][u] + 1;
                que.push({v, np});
            }
        }
    }

    // 处理工单
    while(q--)
    {
        int a;
        ll L;
        cin >> a >> L;

        int p = L % 2;
        int d = dist[p][a];

        bool ans = false;

        if(d != -1 && d <= L)
        {
            ans = true;

            // 起点和终点都是 1 号工人，
            // 但 1 号工人没有任何传送带
            if(d == 0 && L > 0 && g[1].empty())
            {
                ans = false;
            }
        }

        if(ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
