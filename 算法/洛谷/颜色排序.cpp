#include<bits/stdc++.h>
using namespace std;

void ColorSort(int a[],int n)
{
    int i=0,j=0,k=n-1,temp;
    while(j<=k)
        switch(a[j])
        {
            case 1:temp=a[i];a[i]=a[j];a[j]=temp;i++;j++;break;
            case 2:j++;break;
            case 3:temp=a[j];a[j]=a[k];a[k]=temp;j++;k--;break;
        }

}