#include<iostream>
int main()
{
    int n;
    printf("请输入一个整数：");
    scanf("%d",&n);
    int total = 0;
    while(n>0)
    {
        printf("%d",n%10);
        n/=10;
        total++;
    }
    printf("\n总位数为：%d",total);
    return 0;
}