#include<iostream>
// using namespace std;
// int main()
// {
//     int a,b,c;
//     scanf("%d %d",&a,&b);
//     printf("%d\n", a+b);
//     c = a-b;
//     printf("%d",c);
//     return 0;
// }
int main()
{
    const int ALL = 100;
    int prince;
    printf("请输入：");
    scanf("%d",&prince);
    int change = ALL - prince;
    printf("找零：%d",change);
    return 0;
}