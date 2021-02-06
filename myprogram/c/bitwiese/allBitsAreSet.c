#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define BINARY_PRINT_STRING "\n %c%c%c%c%c%c%c%c \n"
#define BYTE_TO_BINARY(x) \
	(x & 0x01 ? '1':'0'), \
	(x & 0x02 ? '1':'0'), \
	(x & 0x04 ? '1':'0'), \
	(x & 0x08 ? '1':'0'), \
	(x & 0x10 ? '1':'0'), \
	(x & 0x20 ? '1':'0'), \
	(x & 0x40 ? '1':'0'), \
	(x & 0x80 ? '1':'0') 

int allBitsAreSet(int n)
{
	if((n&(n+1)) == 0 ) {
		printf("Yes set %x %x \n",n,(n&(n+1)));
		return true;
	}
	return false;
}

int bitalternOrd(int n)
{
	n = n ^ (n >> 1);
	return allBitsAreSet(n);
}

int bitalternOrdrange(int n, int l, int r)
{
	int num,prev,curr;

	num = n >> ( l -1);
	prev = num & 1;
	num = num >> 1 ;
}
int count(int n)
{
	int count  =0;
	while(n) {
		count++;
		n = n&(n-1);
	}

	return count;
}

/* count set bit using look up table 1111 1111  */
int bits_set[256] = { 0,1,1,2,1,2,2,3,1,2,2 };
int loopup_table(int n)
{
	return ( bits_set[n & 255] + bits_set[(n>>8) & 255] + bits_set[(n>>16)& 255] + bits_set[(n>>24) & 255]);
}
int main()
{
	int n = 7,x= 0b010101001;

	printf(BINARY_PRINT_STRING,"%d %x\n ",BYTE_TO_BINARY(n),loopup_table(n),n);
	printf("hello %s,%x \n",allBitsAreSet(n)?"Yes all set One":"no zero there",n);
	printf("hello %s,%x \n",bitalternOrd(x)?"Yes alternet Order":"no alt order",x);
}
