#include<bits/stdc++.h>
using namespace std;

void CountSort(int A[],int n,int B[],int k)
{
    int i,num[k+1]={0};
    for(int i=0;i<n;i++)
        num[A[i]]++;
    for(int i=0;i<=k;i++)
        num[i]=num[i-1]+num[i];
    for(i=n-1;i>=0;i--)
        B[--num[A[i]]]=A[i];
    
}