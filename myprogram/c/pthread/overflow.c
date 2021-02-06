#include <stdio.h>
#include <string.h>

int func()
{
	printf(" get the cash \n");
	return 0;
}

int main()
{
	char buf[20];
	const char mypas[] = "welcome";
	char buf2[20];
	int i=0;
	memset(buf,0,20);
	memset(buf2,0,20);

	while (1) {
		gets(buf);
		strcpy(buf2,buf);
		printf("%s %s %s \n",buf2,buf,mypas);
		if(strcmp(mypas,buf2) == 0) {
			printf("ture pass \n");
			return func();
		} else { printf("try again \n");
			printf("%s \n",buf);
		}
	}
}
