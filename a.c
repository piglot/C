#include<stdio.h>
int M=0x11121314;
#define f(M) (M&0xFF000000)>>24,(M&0xFF0000)>>16,(M&0xFF00)>>8,M&0xFF

int main()
{
    printf("%d.%d.%d.%d\n", f(M));
    return 0;
}

