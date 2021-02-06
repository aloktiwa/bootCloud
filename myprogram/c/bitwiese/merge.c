#include <stdio.h>


int countB(int a)
{
	int c=0;
	
	while(a) {
		c++;
		a &= a-1;
	}
	return c;
}
int countA(int a)
{
	int c;

	for(c=0;a;a &=(a -1)) {
//		c += a&1;
		c++;
	}
	return c;
}
int main()
{
	unsigned int a=10,b=11;
	int ai = 15;
	printf("%d \n",countA(ai));
}

