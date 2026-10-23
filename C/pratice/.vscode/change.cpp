#include<iostream>
// void swap(int &a,int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// int main()
// {
//     int a;
//     int b;
//     printf("请输入两个整数：");
//     scanf("%d %d",&a,&b);
//     swap(a,b);
//     printf("a=%d\n",a);
//     printf("b=%d\n",b);
// }
int main()
{
    int a;
    int b;
    printf("请输入两个整数：");
    scanf("%d %d",&a,&b);
    int temp;
    temp = a;
    a = b;
    printf("a=%d\n",a);
    printf("b=%d\n",temp);
}