#include<iostream>
int main()
{
    int n;
    scanf("%d",&n);
    int i=1;
    int first=1;
    while(i<n)
    {
        first*=10;
        i++;
    }
    i=first;
    while(i<first*10)
    {
        int temp=i;
        int sum=0;
        do
        {
            int d=temp%10;
            temp/=10;
            int p=1;
            int j=0;
            while(j<n)
            {
                p*=d;
                j++;
            }
            sum+=p;
        }while(temp>0);
        if(sum==i)
        {
            printf("%d ", i);
        }
        i++;
    }
    return 0;
}