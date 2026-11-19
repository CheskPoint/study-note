
#include <bits/stdc++.h>
using namespace std;

struct Ticket
{
    int price;  // 地铁票价
    int time;   // 获得优惠券的时间
    bool used;  // 是否使用
};

int main()
{
    int n;
    cin >> n;
    vector<Ticket> a;
    int left = 0;
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        int type, price, time;
        cin >> type >> price >> time;

        // 先处理过期的优惠券
        while(left < a.size() && time - a[left].time > 45)
        {
            left++;
        }

        // 乘坐地铁
        if(type == 0)
        {
            sum += price;

            // 获得一张新的优惠券
            a.push_back({price, time, false});
        }
        // 乘坐公交
        else
        {
            bool flag = false;

            // 从最早的有效优惠券开始寻找
            for(int j = left; j < a.size(); j++)
            {
                if(a[j].used == false && a[j].price >= price)
                {
                    // 使用这张优惠券
                    a[j].used = true;

                    flag = true;
                    break;
                }
            }

            // 没有找到可以使用的优惠券
            if(flag == false)
            {
                sum += price;
            }
        }
    }

    cout << sum;

    return 0;
}
