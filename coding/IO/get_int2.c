#include<stdio.h>
/*input an interger
*/
int main()
{
    int x;
    char ch;
    while(scanf("%d",&x)!=1)
    {
        while((ch=getchar())!='\n')  //same as scanf("%*s");
            putchar(ch);
        printf(" is not an interger.Please re-input.\n");
    }
    printf("x=%d\n",x);
    return 0;
}

