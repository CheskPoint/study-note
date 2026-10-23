#include <iostream>

// 包含流操作算子库
#include <iomanip>
using namespace std;

// 定义常量PI，后面可以直接用PI代替后面的数值
#define PI 3.14159265358979323846

int main()
{
    int n;
    // 请在Begin-End之间添加你的代码，输入n，按不同的精度输出 PI。
    /********** Begin *********/
    cin>>n;
    // while(a<n)
    // {
    //     cout<<fixed<<setprecision(a)<<PI<<endl;
    //     a++;
    // }
    for(int a=n;a<=2*n;a++)
    {
        cout<<fixed<<setprecision(a)<<PI<<endl;
    }
    
    /********** End **********/
    return 0;
}
