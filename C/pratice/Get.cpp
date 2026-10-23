#include<stdio.h>
#include<string.h>
#include <cstdlib>
int main(int argc, char *argv[])
{
    // int ch;
    // while((ch = getchar()) != EOF)
    // {
    //     putchar(ch);
    // }
    // printf("EOF\n");
    // return 0;
    char s[]="Hello";
    char *p=strchr(s,'l');
    char c= *p;
    *p='\0';
    char *t=(char *)malloc(strlen(s)+1);
    strcpy(t,s);
    printf("%s\n",t);
    free(t);
    
    return 0;
}