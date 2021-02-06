#include <stdio.h>

#define jint(a,b) (a#b)
int main()
{
	long a =19;
	typeof(long * ) b;
	b = a;
	printf("%s \n",jint(1,2));
}
