#include<bits/stdc++.h>
using namespace std;

void ColorSort(int a[],int n)
{
    int i=0,j=0,k=n-1,temp;
    while(j<=k)
        switch(a[j])
        {
            case 1:temp=a[i];a[i]=a[j];temp=a[j];i++;j++;break;
            case 2:j++;break;
            case 3:temp=a[j];a[j]=a[k];temp=a[k];j++;k--;break;
        }

}