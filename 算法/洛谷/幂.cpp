#include <bits/stdc++.h>
using namespace std;

void f(int x)
{
    if(x == 0)
    {
        cout << "0";
        return;
    }

    int i = 0;
    int p = 1;

    while(p <= x / 2)
    {
        p *= 2;
        i++;
    }

    if(i == 0)
        cout << "2(0)";
    else if(i == 1)
        cout << "2";
    else
    {
        cout << "2(";
        f(i);
        cout << ")";
    }

    if(x > p)
    {
        cout << "+";
        f(x - p);
    }
}

int main()
{
    int n;
    cin >> n;

    f(n);

    return 0;
}