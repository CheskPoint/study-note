#include<iostream>
int main()
{
    int ex;
    int start;
    scanf("%d %d",&start,&ex);
    int h1 = start/100;
    int m1 = start%100;
    int sum1 = h1*60+m1;
    int sum = sum1+ex;
    int h=sum/60;
    int m=sum%60;
    printf("%d%d\n",h,m);
    return 0;
}