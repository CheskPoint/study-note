#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n;
    scanf("%d", &n);

    // if (n == 0) {
    //     printf("1\n0\n");
    //     return 0;
    // }

    // int cnt = 0;
    // int m = n;
    // int temp = n;


    // while (temp > 0)
    // {
    //     temp /= 10;
    //     cnt++;
    // }
    // printf("%d\n", cnt);  


    // int div = 1;
    // for (int i = 1; i < cnt; i++) {
    //     div *= 10;
    // }

    // while (div > 0)
    // {
    //     printf("%d ", m / div);  
    //     m = m % div;             
    //     div /= 10;               
    // }
    int cnt=0;
    int mask=1;
    int t=n;
    while(t>9){
        t/=10;
        mask*=10;
    } 
    printf("%d\n", mask);
    // int mask=pow(10,cnt-1);
    do
    {
        int d = n/mask;
        printf("%d ", d);
        if(mask>9)
        {
            printf(" ");
        }
        n %= mask;
        mask/=10;
    }while(mask>0);
    printf("\n");
    return 0;
}
