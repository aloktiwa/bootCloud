#include <stdio.h>
#define BINARY_PRINT_STRING " >>%c%c%c%c%c%c%c%c <<"
#define BYTE_TO_BINARY(x) \
	(x & 0x01 ? '1':'0'), \
	(x & 0x02 ? '1':'0'), \
	(x & 0x04 ? '1':'0'), \
	(x & 0x08 ? '1':'0'), \
	(x & 0x10 ? '1':'0'), \
	(x & 0x20 ? '1':'0'), \
	(x & 0x40 ? '1':'0'), \
	(x & 0x80 ? '1':'0') 

#define SIZEOF(obj) ((char *)(&obj + 1) - (char *)&obj)


int allbitset(int n)
{
	if((n & ( n+1)) == 0)
		return 1;

	return 0;
}

int sigbit(int n)
{
	int sig;
	if(allbitset(n) == 1)
		return 0;
	sig = 1 & ( n >>  (sizeof(n)*4 -1));
	return sig;
}
int detget(int x, int y)
{
	return ( (x ^ y ) < 0);
}


int min( int x , int y)
{
	int r;
	return ( y ^ ((x ^ y)));
}
int main()
{
	char sg = 2;
	long long  xy = 0xff00fe0a;
	unsigned char *p = (char *)&xy;
	printf("%x %x %x %x [%x] \n",0[p],1[p],p[2],3[p],xy);
	xy = (p[0] << 24 | p[1] << 8 | p[2] >> 8 | p[3] );
	xy = 0xff001234;
	printf("%x \n",(xy >> 4 ) & 0xf | (xy  << 4) & 0xf0 | (xy >> 4) & 0x0f00 | ( xy << 4) & 0xf000);
	printf("%x %x %x %x [%x] \n",0[p],1[p],p[2],3[p],xy);
	printf("%d ",min(2000,100));
	printf("%d %u %x \n",sg,sg,SIZEOF(sg));
//	printf(BINARY_PRINT_STRING,BYTE_TO_BINARY(-20));
	printf("%d \n", (-20 & ~(1UL << sizeof(int)*4)));

	printf("hello  %d\n",detget(2,-2));
}
