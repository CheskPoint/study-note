#include <stdio.h>
enum COLOR { RED, YELLOW, GREEN,NumCOLORS};
int main(int argc, char *argv[])
{
    int color=-1;
    const char *ColorName[NumCOLORS]={"RED","YELLOW","GREEN"};
    char *colorname=NULL;
    printf("Please input a color :");
    scanf("%d",&color);
    if(color>=0 && color<NumCOLORS)
    {
        colorname=ColorName[color];
    }
    else
    {
        colorname="Unknown";
    }
    printf("The color you entered is: %s\n", colorname);

}
























// #include<stdio.h>
// enum color{red,yellow,green};
// void f(enum color c)
// {
//     enum color t=red;

//     scanf("%d",&t);
//     f(t);
// }

// void f(enum color c)
// {
//     printf("%d\n",c);
// }











// #include <stdio.h>
// enum COLOR { RED, YELLOW, GREEN };
// int main(int argc, char *argv[])
// {
//     int color=-1;
//     const char *colorname=NULL;

//     printf("Please input a color ):");
//     scanf("%d",&color);
//     switch(color)
//     {
//         case RED:colorname="RED";break;
//         case YELLOW:colorname="YELLOW";break;
//         case GREEN:colorname="GREEN";break;
//         default:colorname="Unknown";break;
//     }
//     printf("The color you entered is: %s\n", colorname);
//     return 0;
// }
