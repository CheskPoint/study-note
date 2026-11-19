#include<bits/stdc++.h>
using namespace std;

//
int getvalue(char c)
{
    if('c'>='0'&&'c'<='9')
        return 'c'-'0';
    if('c'>='A'&&'c'<='F')
        return 'c'-'A'+10;
}

char getChar(int x)
{
    if(x<10)
        return x+'0';
    return x-10+'A';
}

bool check(string s)
{
    int l=0;
    int r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
            return false;
        
        l++;
        r++;
    }
    return true;
}

string add(string a,string b,int N)
{
    string ans="";
    int i=a.size()-1;
    int j=b.size()-1;
    int carry=0;

    while(i>=0||j>=0||carry)
    {
        int x=0,y=0;
        if(i>=0)
            x=getvalue(a[i--]);
        if(j>=0)
            y=getvalue(b[j--]);
        int t=x+y+carry;
        ans.push_back(getChar(t%N));
        carry=t/N;
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int N;
    string M;
    cin>>N>>M;
    for(int step=0;step<=30;step++)
    {  
        if(check(M))
        {
            cout<<"STEP="<<step;
            return 0;
        }

        if(step==30)
            break;
        
            string rev=M;
            reverse(rev.begin(),rev.end());
            M=add(M,rev,N);
    }
    cout<<"Impossbile!";
    return 0;
}