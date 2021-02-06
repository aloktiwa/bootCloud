#include<stdio.h>


struct packd {
	unsigned int :3;
	unsigned int f1:1;
	unsigned int f2:1;
	unsigned int f3:1;
	unsigned int type:7;
	unsigned int index:18;
};
int main()
{
	char  a = -32;
	int n = 19;
	
	struct packd pd;
	pd.f1=1;pd.f2=3;
	pd.type=127;
	pd.index = 0xf2;
		printf("%d %d %d %d \n", pd.f1, pd.f2, pd.type, pd.index);
	printf("%d  ==  %d \n", ((n >> 4) & 1), (n & ~(0x1 << 4)));

	printf("\nNegative Right Shift by 1 Bit : %d",a >> 1);
	printf("\nNegative Right Shift by 2 Bits : %d",a >> 2);
	printf("\nNegative Right Shift by 3 Bits : %d",a >> 3);
	printf("\nNegative Right Shift by 3 Bits : %d",a >> 4);

	printf("\nNegative left Shift by 1 Bit : %d",a << 1);
	printf("\nNegative left Shift by 2 Bits : %d",a << 2);
	printf("\nNegative left Shift by 3 Bits : %d",a << 3);
	printf("\nNegative left Shift by 3 Bits : %d",a << 4);

	return(0);
}
