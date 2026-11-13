#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

int main()
{
    int n;
    cin >> n;

    cpp_int a = 1;
    cpp_int s = 0;

    for(int i = 1; i <= n; i++)
    {
        a = a * i;
        s = s + a;
    }

    cout << s;

    return 0;
}