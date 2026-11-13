#include<stdio.h>
#include<iostream>

using namespace std;

int xb,yb;//B
int xh,yh;//马
int pand[30][30];//棋盘
long long f[30][30] = {0};//标记走到某点的路径
int main()
{
    cin>>xb>>yb>>xh>>yh;//输入坐标
    xb+=2;
    yb+=2;
    xh+=2;
    yh+=2;//平移防止越界
    //边界赋值

    //马脚
    pand[xh][yh]=1;
    pand[xh+1][yh+2]=1;
    pand[xh+1][yh-2]=1;
    pand[xh-1][yh+2]=1;
    pand[xh-1][yh-2]=1;
    pand[xh+2][yh+1]=1;
    pand[xh+2][yh-1]=1;
    pand[xh-2][yh+1]=1;
    pand[xh-2][yh-1]=1;

    //计算f(x,y)
    f[1][2]=1;//起点为1
    for(int i=2 ;i<=xb;i++)
    {
        for(int j=2;j<=yb;j++)
        {
            if(pand[i][j]==1) 
            {
                f[i][j]=0;//如果是马脚则为0
                continue;
            }
            f[i][j]=f[i-1][j]+f[i][j-1];
        }
    }
    cout<<f[xb][yb]<<endl;
    return 0;
}