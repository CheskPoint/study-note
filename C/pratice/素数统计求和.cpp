#include<iostream>
int isPrime(int i)
{
    int ret=1;
    for(int j = 2; j < i; j++)
    {
        if(i % j == 0)
            {
            ret = 0;
            break;
        }
    }
    return ret;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int sum = 0;
    int cnt=0;
    if(n==1)
    {
        n=2;
    }
    for(int i = n; i <= m; i++)
    {
        if(isPrime(i))
        {
            sum += i;
            cnt++;
        }
        // int isPrime = 1;
        // for(int j = 2; j < i; j++)
        // {
        //     if(isPrime(i))
        //     {
        //     sum += i;
        //     cnt++;
        //     }
        //     // if(i % j == 0)
        //     // {
        //     //     isPrime = 0;
        //     //     break;
        //     // }
        // }

        // if(isPrime == 1)
        // {
        //     sum += i;
        //     cnt++;
        // }
    }
    printf("%d %d",cnt,sum);
    return 0;
}