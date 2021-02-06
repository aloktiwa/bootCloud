int main()
{
	int x = 0b0111000110 | 0x1234f000;
	int y = 0b0001111010;
	printf("%.8x %.8x \n",x,y);
	printf("%.8x \n",(unsigned int)( x & ~(~(~0 << 7) << 5) | (y & (~(~0 << 7) << 5))));
	printf("%.8x \n",(unsigned int)(~(~0 << 7) << 5));
}

