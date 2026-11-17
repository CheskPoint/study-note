
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = 1;

    // 找到所在的对角线
    while(n > s)
    {
        n -= s;
        s++;
    }

    int a, b;

    if(s % 2 == 0)
    {
        a = n;
        b = s - n + 1;
    }
    else
    {
        a = s - n + 1;
        b = n;
    }

    cout << a << "/" << b;

    return 0;
}
