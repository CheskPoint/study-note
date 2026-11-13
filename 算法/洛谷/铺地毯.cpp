#include<iostream>
using namespace std;
int x,y,n;
int prime=-1;//是否被覆盖
int a[1005][5];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4];
        a[i][3]=a[i][3]+a[i][1];//递推式，矩形坐标关系
        a[i][4]=a[i][4]+a[i][2];//递推式
    }
    cin>>x>>y;
    for(int i=n;i>=1;i--)
    {
        if(x>=a[i][1]&&x<=a[i][3]&&y>=a[i][2]&&y<=a[i][4])//在矩形内
        {
            cout<<i;
            prime=1;
            break;
        }
    }
    if(prime==-1)
        cout<<prime;
    return 0;
} 