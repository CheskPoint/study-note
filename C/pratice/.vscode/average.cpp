#include<iostream>
int main()
{
    // int a,b;
    // printf("输入两个整数：");
    // scanf("%d %d",&a,&b);
    // double c = (a+b)/2.0;
    // printf("平均值是%lf\n",c);
    // return 0; 
    int n;
    int sum=0;
    int count=0;
    printf("请输入整数：");
    do{
        scanf("%d",&n);
        if(n==-1)
        {
            break;
        }
        sum+=n;
        count++;
    }while(1);
    // do{
    //     scanf("%d",&n);
    //     if(n!=-1)
    //     {
    //         sum+=n;
    //         count++;
    //     }
    // }while(n!=-1);
    printf("平均数是：%lf\n", 1.0*sum/count);
    return 0;
}