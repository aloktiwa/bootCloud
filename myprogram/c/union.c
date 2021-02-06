#include <stdio.h>
#include <stdlib.h>



extern char **environ;
union  {
	unsigned short val;
	unsigned char byte[2];
	struct {
		signed short a:1;
		signed short b:1;
		signed short c:1;
		signed short d:1;
	}F1;
}U1;

int main(int argc,char **argv,char**envp)
{
	U1.val = 0x1234;
	int i;
	for(i=0;environ[i] != NULL;i++) {
		printf("%s \n",envp[i]);
	}
	char *us = getenv("USER");
	printf("PATH : %s\n", (char *)((us = getenv("PATH"))?us:NULL));
//	printf("HOME : %s\n", getenv("HOME"));
//	printf("ROOT : %s\n", getenv("ROOT"));
#if 0
	for(i=0;i<10000;i++) {
	printf("%d %d %d %d \n",U1.F1.a++,U1.F1.b,U1.F1.c++,U1.F1.d);
//	printf("%x %x \n",U1.byte[0],U1.byte[1]);
//	printf("%x \n",U1.val);
	
	sleep(2);
	}
#endif
}
