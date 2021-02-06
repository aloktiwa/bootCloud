#include <stdio.h>

int setbits(int x, int p, int n, int y)
{
	return ( x & ~(~(~0 << n) << (p + 1 -n)) | 
			 y & ~(~0 << n) << (p + 1 -n));
}

int ispow2(int n)
{
		return (n &&(!(n&(n-1))));

}

int turnonbit(int n, int k) {
	return (n | ( 1 << (k -1)));
}
int turnoffbit(int n, int k) {
	return (n & ~( 1 << (k -1)));
}
int countposSetbit(int n)
{	int pos=0;
	if(!ispow2(n)) {
		printf("invalid number");
		return -1;
	}
	while(n) {
		n = n >> 1;
		pos++;
	}
	return pos;
}
int main(int argc , char*argv[])
{	
	int y = 0x123f3f;
	int n=-1;
	int x = 0x12340f0f;
	if(argc > 1) {
		n=atoi(argv[1]);
	}

	printf("%d \n",turnonbit(n,5));
	printf("%d \n",turnoffbit(n,5));
	printf(" >> [%d],pos %d \n",n,countposSetbit(n));

	int i=0;
	for(i=0;i< 2; i++)
	{
		printf("%d %d \n",i ,setbits(x,9,5,y));
	}

	printf("%x %x %x \n",x,y,setbits(x,6,3,y));
}
