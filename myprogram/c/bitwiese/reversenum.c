#include  <stdio.h>
// input  0xAB33CD55
// output 0x

int revNum(int n)
{
	int x = n;

	n = (n >> 16) | (n << 16) ;// 0x12345678 -> 0x5678 1234
	printf( "%x <-> %x\n",x,n);
	n = ((n&0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8) ;//  0x5678 1234 -> 0x78 56 34 12
	printf( "%x <-> %x\n",x,n);
	n = ((n&0xf0f0f0f0) >> 4) | ((n&0x0f0f0f0f) << 4) ;// 0x78 56 34 12 -> 0x 8 7 6 5 4 3 2 1
	printf( "%x <-> %x\n",x,n);
	n = ((n&0xcccccccc) >> 2) | ((n&0x33333333) << 2) ; // 0x 1000 0111 0110 0101 0100 0011 0010 0001 -> 0b 0010 1101 0101 0010 1100 1000 0100
	printf( "%x <-> %x\n",x,n);
	n = ((n&0xaaaaaaaa) >> 1) | ((n&0x55555555) << 1);
	printf( "%x <-> %x\n",x,n);

	return n;
}

int swapnum(int *x,int *y)
{
	*x = *x ^ *y;
	*y = *y ^ *x;
	*x = *x ^ *y;
	return 0;
}
int swapbitl(int n,int p1,int p2)
{
	n = n ^ ( 1 << p1);

}
int swapbit(int n,int p1,int p2)
{
	int bit1, bit2,x;
	bit1 = (n >> p1) & 1;
	bit2 = (n >> p2) & 1;
	x = bit1 ^ bit2;

	x = (x << p1 ) | ( x << p2);

	return ( n ^ x);
}

int clearbit(int n,int p1)
{
	n = n & ~( 1UL << p1);
	return n;
}
int revnum(int n)
{
	int res=0;
	int pos = 31;
	while( n)
	{
		res |= (n&1) << pos;
		 n = n >> 1 ; // remove last bin
		pos--;
	}
	return res;
}
int main()
{
	int n = 0x00001001,x=100,y=200;
	printf("%x %x\n",n, revnum(n));
	revNum(0x12345678);
	revNum(0x00001001);
}
