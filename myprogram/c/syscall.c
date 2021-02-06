#include <sys/syscall.h>
//#include <stdio.h>

long long base;
int main()
{
	char buff[30];
	syscall(SYS_write,2,"Hello workd\n",14);
//	read(0,&buff,20);
//	base = puts("===");
//	puts(buff);
	//printf("Hello world\n");
	//write(1,"Hello world\n",14);
}
