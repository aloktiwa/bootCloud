#include <stdio.h>

int (*ptr[5])(unsigned long n);

int count;

typedef int (*funP)(unsigned long n);
int foo2(unsigned long n) 
{
	printf("%s >> %x %d \n",__FUNCTION__,n,count++);
	return 0;
}
int foo1(unsigned long n)
{
	printf(" >> %x %d %s \n",n,count++,__FUNCTION__);
	if(n == 0) return 0;
	int (*p)(unsigned long) = (funP)n;//(int(*)(unsigned long))n;
	p((unsigned long)0);
	return 1;
}

int main(int arg,char *argv[],char *ENV[])
{
	int i;
	for(i=0;ENV[i] != NULL;i++)
		printf("%s \n",ENV[i]);
	for(i=0;i<5;i++)
		ptr[i] = foo1;

	for(i=0;i<5;i++)
			ptr[i]((unsigned long)foo2);

}
