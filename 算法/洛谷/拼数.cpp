#include<bits/stdc++.h>
using namespace std;

int n;
string s[100005];
bool com(string a,string b)
{
   return a+b>b+a;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    sort(s+1,s+1+n,com);
    for(int i=1;i<=n;i++)
    {
        cout<<s[i];
    }
    return 0;
}