#include<iostream>
#include<stdio.h>
int main()
{
    int m,n;
    int temp;
    scanf("%d/%d",&m,&n);
    int a = m;
    int b = n;
    while(b>0)
    {
        temp= a % b;
        a=b;
        b=temp;
    }
    printf("%d\n",a);
    printf("%d/%d\n",m/a,n/a);
    return 0;

}