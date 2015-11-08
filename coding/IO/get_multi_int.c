#include<stdio.h>
#define MAXSIZE 40

/*input a list of interger numbers in a line and press "enter" to ends input
*/
int main()
{
	int data[MAXSIZE];
	int i=0,j;
	printf("Input a list of numbers.\n");
	while(1)
	{
		scanf("%d", &data[i++]);
		if(getchar()=='\n')
			break;
	}
	
	printf("Your input numbers is:\n");
	for(j=0;j<i;j++)
		printf("%d ",data[j]);
	printf("\n");

	return 0;
}

