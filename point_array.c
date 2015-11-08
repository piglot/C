#include<stdio.h>

int main()
{
    int v[2][10]={{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
    int (*a)[10]=v;
    printf("*a=0x%x, **a=%d\n", *a,**a);
    printf("(*a+1)=0x%x, *(*a+1)=%d\n", *a+1,*(*a+1));
    printf("*(a+1)=0x%x, **(a+1)=%d\n", *(a+1),**(a+1));
    printf("(*a+1)-*a=%d, *(a+1)-*a=%d\n", (int)(*a+1)-(int)*a,(int)*(a+1)-(int)*a);
    return 0;
}

