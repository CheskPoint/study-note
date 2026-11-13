#include<bits/stdc++.h> 
using namespace std;
int L,N;
int x[5005];
int main()
{
    cin>>L>>N;
    int mintime=0,maxtime=0;
    for(int i=1;i<=N;i++)
    {
        cin>>x[i];
        int n=min(x[i],L-x[i]+1);//单个士兵最少时间
        int m=max(x[i],L-x[i]+1);//单个士兵最长时间
        mintime=max(mintime,n);//最少时间中最大的时间可以包含小时间
        maxtime=max(maxtime,m);//最长的时间包含小的
    }
    cout<<mintime<<" "<<maxtime;
    return 0;
    
}