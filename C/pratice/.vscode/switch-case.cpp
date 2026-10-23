#include<stdio.h>
int main()
{
    int type;
    scanf("%d",&type);
    switch(type)
    {
        case 1:
            printf("H");
            break;
        case 2:
            printf("e");
            break;
        case 3:
            printf("l");
            break;
        case 4:     
         printf("l");
                break;  
        case 5:
            printf("o");
            break;
        default:
            printf("Invalid input");
            break;
    }
    return 0;
}