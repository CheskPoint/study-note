#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,round[105] = {0},now = 0,counts=0;
    cin>>n>>m;
    while(counts<n)
    {
        for(int i=1;i<=m;i++)
        {
            now = (now+1>n ? 1:now+1);
            while(round[now])
                now = (now+1>n) ? 1:now+1;
        }
        counts++;
        round[now]++;
        cout<<now<<" ";
    }
    return 0;
}