#include<iostream>
int main()
{
    int i,j;
    int n;
    scanf("%d",&n);
    i=1;
    while(i<=n)
    {
        j=1;
        while(j<=i)
        {
            printf("%d*%d=%-2d ",j,i,i*j);
            j++;
            if(i*j<10)
            {
                printf("   ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
        i++;
    }
    // for(i=1;i<=9;i++)
    // {
    //     for(j=1;j<=i;j++)
    //     {
    //         printf("%d*%d=%-2d ",j,i,i*j);
    //     }
    //     printf("\n");
    // }
    return 0;
}