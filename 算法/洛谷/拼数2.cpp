#include<bits/stdc++.h>
using namespace std;

bool com(string a,string b)
{
    return a+b>b+a;
}
int main()
{
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s.begin(),s.end(),com);
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }
    return 0;
}