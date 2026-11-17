#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int b=n-1;//进位制
    string s[10][10];

    //二维字符串数组，存整张输入的加法表格
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>s[i][j];
    
    //存所有需要分配数字的字母       
    char c[10];
    for(int i=0;i<b;i++)
        c[i]=s[0][i+1][0];

    //初始化排列
    int p[10];//用来枚举的数字排列
    for(int i=0;i<b;i++)
        p[i]=i;//p[k]就是分配给c[k]的数字
    do
    {
        int num[26]={};//字母 → 数字的映射表,num[ch-'A'] = 值
        char digit[10];//数字 → 字母的映射表，和num反过来
        //digit[1]='A'，数字1写成字母A

        //建立对应关系
        for(int i=0;i<b;i++)
        {
            num[c[i] - 'A']=p[i];
            digit[p[i]]=c[i];  
        }
        
        bool ok=true;//先假设当前这套字母数字分配方案是正确的
        //只要有一处加法和表格对不上，就执行ok=false;break;
        for(int i=1;i<n && ok;i++)
        {
            for(int j=1;j<n;j++)
            {
                int x=num[s[i][0][0] - 'A']
                +num[s[0][j][0] - 'A'];
                
                std::string ans;
                //进制转换
                if(x<b)
                    ans=digit[x];
                else
                {
                    ans = digit[x/b];
                    ans+=digit[x%b];
                }
                if(ans!=s[i][j])
                {
                    ok=false;
                    break;
                }
            }
        }

        //找到正确答案
        if(ok)
        {
            for(int i=0;i<b;i++)
            {
                if(i!=0) cout<<" ";
                cout<<c[i]<<"="<<p[i];
            }
            cout<<endl<<b<<endl;
            return 0;
        }
    } while (next_permutation(p,p+b));
    cout<<"ERROR!"<<endl;
    return 0;
    
}