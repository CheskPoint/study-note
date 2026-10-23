#include<iostream>
int main()
{
    printf("请输入一个数字：");
    int x;
    scanf("%d",&x);
    int a= x/16;
    int b= x%16;
    printf("%X\n",x);
    return 0;
}
