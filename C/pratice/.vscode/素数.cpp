#include <cstdio>   // 对应 printf/scanf 的标准头文件
#include<iostream>

int main()
{
    int n, m;
    printf("请输入一个数：");
    scanf("%d", &n);
    int cnt=0;
    // for(m = 2; m <= n; m++)
    while(cnt < 50)
    {
        int isPrime = 1;  
        for(int i = 2; i<n; i++)  
        {
            if(n % i == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if(isPrime == 1)
        {
            printf("%d ", n);  
            cnt++;
        }
        n++;
    }
    printf("\n");
    return 0;
}
