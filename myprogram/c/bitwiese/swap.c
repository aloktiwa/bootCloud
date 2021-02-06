#include  <stdio.h>
// input  0xAB33CD55
// output 0x

int msbshift(void)
{
    printf("Hello, world!\n");
    int Ai = 0xdeadbeef,Bi;
    int B1 = ((Ai & 0xff000000) >> 24 ) | (( Ai & 0x000000ff) << 24) | ((Ai & 0x00ff0000) >> 8 ) | (( Ai & 0x0000ff00) << 8);

    printf("%x \n%x ",Ai,B1);
    return 0;
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
int main()
{
	int n = 28,x=100,y=200;
	printf("%d %d \n",n,swapbit(n,0,3));
	printf("%d %d \n",x,y);
	printf("%d %d %d\n",swapnum(&x,&y),x,y);
	printf("%d %d \n",x,y);
	n = 17;
	printf("%d %d ",n,clearbit(n,4));
}
