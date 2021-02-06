#include <stdio.h>
#include <string.h>

char name[20];
char *main2()
{
	strncpy(name,"avalanche        0000000  999999",20);
}
int main()
{
	char name2[20];
	memset(name,0,20);
	memset(name2,0,20);

	strcpy(name2,main2());
	printf("%s \n",name2);
}
