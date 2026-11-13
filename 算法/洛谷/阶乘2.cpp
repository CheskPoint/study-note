#include <bits/stdc++.h>
using namespace std;

int a[1000] = {0};//记录当前阶乘
int s[1000] = {0};//保存阶乘和

int main()
{
    int n;
    cin >> n;

    a[0] = 1;//开始为1
    int len = 1;//位数为1

    for(int i = 1; i <= n; i++)
    {
        int t = 0;

        for(int j = 0; j < len; j++)
        {
            t += a[j] * i;
            a[j] = t % 10;
            t /= 10;
        }

        while(t)
        {
            a[len++] = t % 10;
            t /= 10;
        }

        t = 0;
        for(int j = 0; j < len; j++)
        {
            t += s[j] + a[j];
            s[j] = t % 10;
            t /= 10;
        }

        int j = len;
        while(t)
        {
            t += s[j];
            s[j++] = t % 10;
            t /= 10;
        }
    }

    int j = 999;
    while(j > 0 && s[j] == 0)
        j--;

    for(; j >= 0; j--)
        cout << s[j];

    return 0;
}