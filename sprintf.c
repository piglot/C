#include<stdio.h>
#include<string.h>
#include<malloc.h>
int main()
{
	char *str=(char *)malloc(10);
	int i;
	i=sprintf(str, "%x", 100);
	printf("%s\n", str);
	printf("%d %d %d\n", i, strlen(str), sizeof(*str));
	printf("short:%d int:%d long:%d char:%d double:%d\n",sizeof(short),sizeof(int),sizeof(long),sizeof(char),sizeof(double));
	return 0;
}

