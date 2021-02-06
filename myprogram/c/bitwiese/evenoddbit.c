#include <stdio.h>

int swapbit(int x)
{
	int even,odd;
	even = x & 0xAAAAAAAA;
	odd = x & 0x55555555;
	return ((even >> 1) | (odd << 1));
}

int isEven(int n) {
	return (!(n & 1));
}
int main()
{
	int x=23;
	int n =10;
	printf("%x %d \n",x,x);
	printf("%d \n",swapbit(x));
	printf("%d %s\n",n,isEven(n)?"even":"odd");
}
