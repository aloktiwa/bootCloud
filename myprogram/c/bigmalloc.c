#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned int *a = ( unsigned int *) malloc(sizeof(int)*4000000000);
	printf("%p %p\n",a,main);
	return 0;
}
