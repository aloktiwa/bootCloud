int main()
{
	int  i =0x01010101;
	printf("[%x] %x\t",i,((i >>2) & 0x33333333 | (i << 2) & 0xcccccccc));
}

