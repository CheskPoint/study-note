#include<stdio.h>
#include<string.h>
int main()
{
    char*a[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int i;
    scanf("%d",&i);
    if(i>=1&&i<=12)
    {
        printf("%s\n",a[i-1]);
    }
    else
    {
        printf("error\n");
    }
    return 0;
    
}