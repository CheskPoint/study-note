
#include<bits/stdc++.h>

#if defined(__has_include)
#  if __has_include(<boost/multiprecision/cpp_int.hpp>)
#    include <boost/multiprecision/cpp_int.hpp>
#    define CPP_INT_AVAILABLE 1
#  else
#    define CPP_INT_AVAILABLE 0
#  endif
#endif

using namespace std;
#if CPP_INT_AVAILABLE
using boost::multiprecision::cpp_int;
#else
using cpp_int = unsigned long long;
#endif

int n,m;
int num[85];
cpp_int ans,p[85],f[85][85];
bool vis[85][85];

// 记忆化搜索
cpp_int dp(int L,int R)
{
    if(vis[L][R])
        return f[L][R];

    vis[L][R]=true;

    if(R-L>=1)
    {
        cpp_int left=num[L]*p[m-(R-L)]+dp(L+1,R);
        cpp_int right=dp(L,R-1)+num[R]*p[m-(R-L)];

        f[L][R]=max(left,right);
    }
    else
    {
        f[L][R]=num[L]*p[m];
    }

    return f[L][R];
}

int main()
{
    cin>>n>>m;

    // 预处理 2 的幂
    p[0]=1;

    for(int i=1;i<=m;i++)
        p[i]=p[i-1]*2;

    // 逐行计算
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>num[j];

        // 初始化访问标记
        memset(vis,0,sizeof(vis));

        ans+=dp(1,m);
    }

    cout<<ans;

    return 0;
}
