#include <stdio.h>
int gcdaldo(int n1,int n2)
{
	if(n1 == n2)
		return n1;
	if(n1 == 0)
		return n2;
	if(n2 == 0)
		return n1;

	if(n1 > n2)
		return gcdaldo(n1-n2,n2);

	return (n1,n2-n1);
}

int gcd2(int a,int b)
{
	if(a == 0)
		return b;
	return gcd2(b%a,a);
}
int main()
{

	printf("gcd %d %x\n",gcdaldo(12,16),12*8);
	printf("gcd %d %x\n",gcd2(16,12),12*8);
}
