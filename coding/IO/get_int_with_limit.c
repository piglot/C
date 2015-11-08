#include<stdio.h>
/*input a interger and limit it 1-10
*/
int main()
{
    int x,status;
    while((status=scanf("%d",&x))!=1 || (x<1 || x>10))
    {
        if(status!=1)
            scanf("%*s");
        printf("Please input a interger between 1 and 10.\n");
    }
    printf("x=%d\n",x);
    return 0;
}
