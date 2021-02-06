#include <stdio.h>



int revers1( int x)
{
	printf("\n");
	x = ( x >> 16)| ( x << 16);
	printf(">> %.8x ",x);
	x = ( x >> 8) & 0x00ff00ff | (0xff00ff00&(x << 8));
	printf(" %.8x ",x);
	x = ( x >> 4) & 0x0f0f0f0f | (0xf0f0f0f0&(x << 4));
	printf(" %.8x ",x);
	x = ( x >> 2) & 0xcccccccc | (0x33333333&(x << 2));
	printf(" %.8x ",x);
	x = ( x >> 1) & 0xaaaaaaaa | (0x55555555&(x << 1));
	printf(" %.8x ",x);



	printf(" << \n");
	return x;
}
int main(){

	int x = 0x45600321;

	printf("%x %x \n",x,revers1(x));

}
