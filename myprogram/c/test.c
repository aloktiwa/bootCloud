#include <stdio.h>
#include <mcheck.h>


int main()
{
	volatile int c=1;
		

	mtrace();
	(char *)malloc(sizeof(long long));
	(long *)malloc(sizeof(long long));
	(long *)malloc(sizeof(long long));

	fprintf(stdout,"malloc is now \n");
//	while( c != EOF) 
{

		c = getchar();
		printf("%d \n",c);
	}
	printf("\n");
}
