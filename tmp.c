#include<stdio.h>

int main()
{
	int a[10]={12,14,52,25,32,31,6,7,23,13};
	int i, j, tmp;
	for(i=0;i<9;i++)
	{
		printf("This is the %dth outsidecycle\n", i+1);
		for(j=0;j<9-i;j++)
			if(a[j]>a[j+1])
			{
			tmp=a[j+1];
			printf("------The %dth insidecycle tmp is: %d\n",j+1,tmp);
			a[j+1]=a[j];
			a[j]=tmp;
			}
		printf("After the %dth outsidecycle tmp is: %d\n",i+1,tmp);
		for(j=0;j<10;j++)
		{
			printf("%d ",a[j]);
		}
		printf("\n");
	}
	printf("Result tmp=%d\n", tmp);
	return 0;
}
