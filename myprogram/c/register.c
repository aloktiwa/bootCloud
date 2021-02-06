#include <stdio.h>

void binx(int n) {
	printf(" bin = ");
	while(n) { 
		printf("%d",n%2);
		n=n/2;
	}
	printf(" \n");
}
int main()
{
	int xx=10;
	register int x;
	const int array[12] =  { 10,12,13,1};
	printf("%d %d %d %d %d \n",array[0],array[2],array[4],array[6],array[9]);
	binx(xx);
	int *p = &xx;
}
