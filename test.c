#include<stdio.h>
#define x 10
int main()
{
    char y=10;
    #if(y==10)
        printf("true");
    #else
        printf("false");
    #endif
     #if(x==10)
        printf("true");
    #else
        printf("false");
    #endif
    return 0;
}