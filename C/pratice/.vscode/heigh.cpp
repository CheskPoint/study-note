#include<iostream>
int main()
{
    // printf("请输入身高的英尺和英寸：");
    // int feet;
    // int inch;
    // scanf("%d %d",&feet,&inch);
    // printf("身高是%f米。\n",((feet+inch/12.0)*0.3048));
    // return 0;
    int cm;
    printf("请输入身高厘米：");
    scanf("%d",&cm);
    int foot = cm/30.48;
    int inch = ((cm/30.48) - foot)*12;
    printf("身高是%d英尺%d英寸。\n",foot,inch);
    return 0;
} 