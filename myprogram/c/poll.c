#include <stdio.h>

#include <string.h>


int main()
{
	int fd=0,fd2=1;

	char buff[20]= {0};

	read(fd,buff,10);
	fprintf(fd2,"%s",buff);
}
