#include<iostream>
int main()
{
    int a;
    int b;
    int c=0;
    printf("请输入一个三位数：");
    scanf("%d",&b);
    // int b1 = b/100;
    // int b2 = (b%100)/10;
    // int b3 = b%10;
    // if(b3 == 0)
    // {
    //     printf("%d%d\n",b2,b1);
    // }
    // else if(b2==0 &&b3 == 0)
    // {
    //     printf("%d\n",b1);
    // }
    // else
    // {
    //     printf("%d%d%d\n",b3,b2,b1);
    // }
    // return 0;
    while(b>0)
    {
        a = b%10;
        c=c*10+a;
        b/=10;
    }
    printf("%d\n",c);
    return 0;
}