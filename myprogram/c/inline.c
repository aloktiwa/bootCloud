#include <stdio.h>

__inline int func() {
	return 2;
}

static __inline__ int func10()
{
	return 10;
}
int main()
{
	int ret ;

	ret = func10() + func();
	printf("%d %d \n",__inline,__inline__):
	return ret;
}
