#include <stdio.h>

#define mysize(type) ((char *)(&type + 1) - (char *)(&type))


struct nd {
//	char *pp;
//	char *ptr;
	char p;
	char a;
	char c;
}nd;
int main()

{
//	int typedef = 10;
	int t =10;
	typeof(int) B =800;
	printf("hellow %d %d %d \n",t,B);
	printf("sizoef %d %d %d\n",sizeof(nd),mysize(nd),sizeof(char *));
}
