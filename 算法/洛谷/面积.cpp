#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    long long x=a*a;
    long long y=b*c;
    if(x=y)
        printf("Alice");
    else
        printf("Bob");
    return 0;
}