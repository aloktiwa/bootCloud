#include <stdio.h>

int func(int n)
{
	if ( n > 0) {
		func((n/10)); //1789
		printf("%d ",n%10);
	}
}
int func2(int n)
{
	if ( n > 0) {
		printf("%d ",n%10);
		func2((n/10)); //1789
	}
}
int main()
{
	func(1789);
	printf("\n");
	func2(1789);
	printf("\n");
}
