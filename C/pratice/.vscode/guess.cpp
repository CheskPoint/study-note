#include<iostream>
#include<random>
#include <stdlib.h>
#include<time.h>
using namespace std;
int main()
{
    // std::random_device rd;  // 获取随机数种子
    // std::mt19937 gen(rd()); // 使用Mersenne Twister算法生成随机
    // std::uniform_int_distribution<> dis(1, 100); // 定义一个1到100的均匀分布
    // int target = dis(gen); // 生成随机数
    // int guess;
    // int n=0;
    // printf("请输入数：");
    // scanf("%d", &guess);
    // while (guess != target) {
    //     n++;
    //     if (guess < target) {
    //         printf("猜小了，请再试一次：");
    //     } else {
    //         printf("猜大了，请再试一次：");
    //     }
    //     scanf("%d", &guess);
    // }
    // printf("恭喜你猜对了！你一共猜了 %d 次。\n", n);
            // srand(static_cast<unsigned>(time(0)));
    srand(time(0));  
    int number = rand()%100 + 1; // 生成1到100之间的随机数
    int count = 0;
    int a= 0;
    printf("我已经想好一个数了，请你猜吧！\n");
    do{
        printf("请猜一个1到100之间的整数：");
        scanf("%d", &a);
        count++;
        if(a < number){
            printf("你猜的数小了，请再试一次。\n");
        }else if(a > number){
            printf("你猜的数大了，请再试一次。\n");
        }
    }while(a != number);
    printf("恭喜你猜对了！你一共猜了 %d 次。\n", count);
    return 0;
}