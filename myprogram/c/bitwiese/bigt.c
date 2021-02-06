#include <stdio.h>

int CON(int x)
{
	x =  (( x >> 16)&0x0000ffff) | ((x << 16)& 0xffff0000);
	return (((x>> 8) & 0x00ff00ff) | (( x << 8) & 0xff00ff00));
}

#define convert(x) (( x >> 24)&0x000000ff | (x << 24)&0xff000000 | (x >> 8)& 0x0000ff00 | (x << 8) & 0x00ff0000 )
int main()
{
	int x = 0xF1F2F3F4;

	printf("%x %x %x\n",x , CON(x),convert(x));
}
