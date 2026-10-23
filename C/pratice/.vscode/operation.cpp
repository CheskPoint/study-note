#include<iostream>
using namespace std;
int main()
{
    // int h1,m1;
    // int h2,m2;
    // printf("请输入小时和分钟：");
    // scanf("%d %d",&h1,&m1);
    // printf("请输入小时和分钟：");
    // scanf("%d %d",&h2,&m2);
    // int total=h1*60+m1;
    // int total2=h2*60+m2;
    // int d = total2-total;
    // if(d<0)
    // {
    //     d = -d;
    //     printf("total1和total2的时间差是%d时%d分钟。\n",d/60,d%60);
    // }
    // else
    // {
    //     printf("total2和total1的时间差是%d时%d分钟。\n",d/60,d%60);
    // }
    // return 0;
    int h1,m1;
    int h2,m2;
    printf("请输入小时和分钟：");
    scanf("%d %d",&h1,&m1);
    printf("请输入小时和分钟：");
    scanf("%d %d",&h2,&m2);
    int ch = h2-h1;
    int cm = m2-m1;
    if(cm<0)
    {
        ch--;
        cm+=60;
    }   
    printf("时间差是%d时%d分钟。\n",ch,cm);
    return 0;
}