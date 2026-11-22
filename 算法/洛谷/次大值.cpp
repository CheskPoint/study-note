#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<long long> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());//从小到大排序
    //去重
    vector<long long> b;
    for(int i=0;i<n;i++)
    {
        if(b.empty()||b.back()!=a[i])
            b.push_back(a[i]);
    }
    if(b.size()<2)
    {
        cout<<-1;
        return 0;
    }
    //最大数和次大取模
    long long ans=b[0]%b[1];
    //如果有第三大的数
    if(b.size()>2)
        ans=max(ans,b[2]);
    cout<<ans;
    return 0;
    
}