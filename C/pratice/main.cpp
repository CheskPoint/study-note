#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }

    printf("%d", m);
    return 0;
} 