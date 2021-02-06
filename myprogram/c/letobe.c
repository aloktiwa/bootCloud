#include <stdio.h>

unsigned long long converbe2(unsigned long long src)
{
	unsigned long long rval;
	unsigned char *data = (char *)&rval;

	data[0] = src >> 56;
	data[1] = src >> 48;
	data[2] = src >> 40;
	data[3] = src >> 32;
	data[4] = src >> 24;
	data[5] = src >> 16;
	data[6] = src >> 8;
	data[7] = src >> 0;

	return rval;
}

unsigned long long converbe(unsigned long long src)
{
	unsigned char c;
	union {
		unsigned long long ull;
		unsigned char c12[8];
	}x;
	x.ull = src;

	c = x.c12[0]; x.c12[0] = x.c12[7]; x.c12[7] =c;
	c = x.c12[1]; x.c12[1] = x.c12[6]; x.c12[6] =c;
	c = x.c12[2]; x.c12[2] = x.c12[5]; x.c12[5] =c;
	c = x.c12[3]; x.c12[3] = x.c12[4]; x.c12[4] =c;

	return x.ull;
}

unsigned int convIntbe2(unsigned int src)
{
	unsigned int rval;
	unsigned char *data = (char *)&rval;

	data[0] = src >> 24;
	data[1] = src >> 16;
	data[2] = src >> 8;
	data[3] = src >> 0;
	return rval;
}
unsigned int convIntbe(unsigned int src)
{
	unsigned char c;
	union {
		unsigned int i32;
		unsigned char cb[4];
	}x;
	x.i32 = src;
	c = x.cb[0];x.cb[0] = x.cb[3];x.cb[3] = c;
	c = x.cb[1];x.cb[1] = x.cb[2];x.cb[2] = c;

	return x.i32;
}

void findmtype()
{
	if(sizeof(void *) == 4 )
		printf(" machine is m32 \n");
	else if(sizeof(void *) == 8)
		printf(" machine is m64 \n");
	else
		printf(" not 32 and 64 bit machine \n");

}

// 56 >> << 56, 40 >> << 40  24  24 8 8 
unsigned long long c12e64(unsigned long long x)
{
	x = ( 
		  ((x & 0xff00000000000000) >> 56)  | 
		  ((x & 0x00000000000000ff) <<  56) |			
		  ((x & 0x00ff000000000000) >> 40)  | 
		  ((x & 0x000000000000ff00) <<  40) |			
		  ((x & 0x0000ff0000000000) >> 24)  | 
		  ((x & 0x0000000000ff0000) <<  24) |			
		  ((x & 0x000000ff00000000) >> 8)   | 
		  ((x & 0x00000000ff000000) << 8)	
		);
		return x;
}
int main()
{
	unsigned long long xx = 0x8765432112345678;
	unsigned int *x12 = (unsigned int *)0xdeadbeef;
	unsigned int x32 = 0xdeadbeef;
	findmtype();
	*x12 = 1000;
	printf("%.16lx %.16lx \n",xx,converbe(xx));
	printf("%.16lx %.16lx \n",xx,c12e64(xx));
	printf("%.16lx %.16lx \n",xx,converbe2(xx));
	printf("%x %x \n",x32,convIntbe(x32));
	printf("%x %x \n",x32,convIntbe2(x32));
	printf("%d %d \n",x32,*x12);
}


