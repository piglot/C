#include<stdio.h>
/*
'a' is an array:

&a + i = a + i*sizeof(a);
 a + i = a + i*sizeof(a[0]);

*/
int main()
{
    int a[4]={1,2,3,4};
    int *p1=(int *)(&a+1);
    printf("a=%x\n", a);
    printf("%x\n", p1[-1]);
    int *p2=(int *)(a+1);
    printf("p2=%x, *p2=%x\n", &p2,*p2);
    printf("&a+1=%x, a+1=%x\n", &a+1,(int *)a+1);
    return 0;
}
