#include<iostream>

int main()
{
    int a;
    printf("请输入一个数：");
    scanf("%d",&a);
    int ret=1;
    // if(a<0)
    // {
    //     printf("输入错误");
    //     return 0;
    // }
    // else if(a==0)
    // {
    //     printf("结果是：1");
    //     return 0;
    // }
    // else
    // {
    //     for(int b=1;b<=a;b++)
    //     {
    //         ret*=b;
    //     }
    // }

    // int b=1;
    // while(b<=a)
    // {
    //     ret*=b;
    //     b++;
    // }

    for( ;a>0;a--)
    {
        ret*=a;
    }
    printf("结果是：%d",ret);
    return 0;
}