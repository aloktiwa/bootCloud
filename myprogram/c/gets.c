#include <stdio.h>

int main()
{
	char buff[200];
	fgets(buff,50,stdin);
//	scanf("%[^\n]s",buff);
//	scanf("%s",buff);

	printf("%s \n",buff);
}
