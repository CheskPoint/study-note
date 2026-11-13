#include<bits/stdc++.h>
using namespace std;

int main()
{
    for(int a=100;a<=333;a++)//三位数
    {
        int b=a*2;//比例
        int c=a*3;
        //设置变量存储防止修改
        int x=a;
        int y=b;
        int z=c;
        int cnt[10]={0};//记录每个数出现的次数
        
        while(x>0)
        {
            int t=x%10;
            cnt[t]++;
            x/=10;
        }

        while(y>0)
        {
            int t=y%10;
            cnt[t]++;
            y/=10;
        }

        while(z>0)
        {
            int t=z%10;
            cnt[t]++;
            z/=10;
        }

        bool prime=true;
        for(int i=1;i<=9;i++)
        {
            if(cnt[i]!=1)
            {
                prime=false;
                break;
            }
        }
        if(prime)
            cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}
