#include<iostream>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     double total=0;
//     double sign=1;
//     for(int i=1;i<=n;i++)
//     {
//         total+=sign/i;
//         sign=-sign;
//     }

//     printf("f(%d)=%.5f", n, total);
//     return 0;
// }
void sum(int begin,int end)
{
    int i;
    int sum=0;
    for(i=begin;i<=end;i++)
    {
        sum+=i;
    }
    printf("%d到%d的和是%0d\n",begin,end,sum);
}
int main()
{
    sum(1,10);
    sum(20,30);
    sum(35,45);
    return 0;
}