#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    int n,m,counts=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(counts<n)
    {
        for(int i=1;i<m;i++)
        {
            q.push(q.front());//取出队头元素再放入队尾
            q.pop();
        }
        cout<<q.front()<<" ";
        q.pop();
        counts++;
    }
    return 0;
}