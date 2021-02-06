#include <stdio.h>

int main()
{
	const volatile int pl =100;
	int *aa = &pl;
	printf("%d %d \n",++*aa,*aa = 200);
	int  A[] = {10,21,42,63,74,95};

	char *a= (int *)&A[0];

	printf("%d %d %d \n",*((int *)a+1) + 1,*(int *)a+2,*((int *)a+3)+2);
	printf("hellw %d \n",*A);
}
