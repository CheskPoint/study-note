#include <bits/stdc++.h>
using namespace std;

// 判断回文
bool check(vector<int> a)
{
    int l = 0;
    int r = a.size() - 1;
    while(l < r)
    {
        if(a[l] != a[r])
            return false;

        l++;
        r--;
    }
    return true;
}

// N进制加法：M + M的倒序数
vector<int> add(vector<int> M, int N)
{
    stack<int> a, b, ans;
    // 原数入栈
    for(int i = 0; i < M.size(); i++)
        a.push(M[i]);

    // 倒序数入栈
    for(int i = M.size() - 1; i >= 0; i--)
        b.push(M[i]);
    int carry = 0;

    // 逐位相加
    while(!a.empty() || !b.empty() || carry)
    {
        int x = 0, y = 0;

        if(!a.empty())
        {
            x = a.top();
            a.pop();
        }

        if(!b.empty())
        {
            y = b.top();
            b.pop();
        }
        int t = x + y + carry;
        ans.push(t % N);
        carry = t / N;
    }

    // 将结果栈转换成数组
    vector<int> res;
    while(!ans.empty())
    {
        res.push_back(ans.top());
        ans.pop();
    }
    return res;
}

int main()
{
    int N;
    string s;
    cin >> N >> s;
    vector<int> M;

    // 将输入的每一位转换成整数
    for(char c : s)
    {
        if(c >= '0' && c <= '9')
            M.push_back(c - '0');
        else
            M.push_back(c - 'A' + 10);
    }

    // 最多进行30次加法
    for(int step = 0; step <= 30; step++)
    {
        if(check(M))
        {
            cout << "STEP=" << step;
            return 0;
        }
        if(step == 30)
            break;

        M = add(M, N);
    }
    cout << "Impossible!";
    return 0;
}
