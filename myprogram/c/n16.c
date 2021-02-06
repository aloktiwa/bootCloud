#include <stdio.h>

int main()
{

	int n = 0x12345678;
	int n16,n8,n4,n2;

	n16 = (n >> 16) | (n << 16);
	n8 = ((n16 >> 8) & 0x00ff00ff ) | ( (n16 << 8) & 0xff00ff00);
	n4 = ((n8 >> 4) & 0x0f0f0f0f) | ((n8 << 4) & 0xf0f0f0f0);
	n2 = ((n4 >> 2)& 0x03030303) | ((n4 << 2) & 0x30303030);


	printf("%.8x %.8x %x %x %x \n",n,n16,n8,n4,n2);
}
