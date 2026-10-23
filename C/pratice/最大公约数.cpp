#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    // int m, n;
    // scanf("%d %d", &m, &n);

    // int r;
    // while (n != 0)
    // {
    //     r = m % n;
    //     m = n;
    //     n = r;
    // }

    // int a,b;
    // int min;
    // scanf("%d %d", &a, &b);
    // if(a<b)
    // {
    //     min = a;
    // }
    // else
    // {
    //     min = b;
    // }
    // int ret=0;
    // for(int i=1;i<=min;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    // {
    //     if(a%i==0 && b%i==0)
    //     {
    //         ret = i;
    //     }
    // }

    int a,b;
    int temp;
    scanf("%d %d", &a, &b);
    while(b!=0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    printf("%d", a);
    return 0;
}