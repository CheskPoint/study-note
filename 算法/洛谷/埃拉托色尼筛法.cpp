#include<bits/stdc++.h>
using namespace std;

void EratoSieve (int A[], int n)
{
    int i,j;
    for(i=2;i<=n/2;i++)
    {
        if(A[i]!=0)
            continue;
        else{
            for(j=2;i*j<=n;j++)
                A[i*j]=1;
        }
    }
}