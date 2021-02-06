#include <stdio.h>

#define SIZEOF(obj) (char *)(&obj + 1) - (char *)(&obj)


#define MYSIZE(obj) typeof(obj) a


int main()
{	
	long long lp;
	char ar[10];
	double dp;
	int *op;

	printf("%d %d %d\n",SIZEOF(lp),SIZEOF(ar),SIZEOF(dp));
//	printf("%d \n",SIZEOF(MYSIZE(int)));
}
