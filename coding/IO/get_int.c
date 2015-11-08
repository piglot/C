#include<stdio.h>
/*input an interger
*/
int main()
{
    int x;
    while(scanf("%d",&x)!=1)
    {
        scanf("%*s");  //same as while(getchar()!='\n');
        printf("Please input an interger.\n");
    }
    printf("x=%d\n",x);
    return 0;
}

