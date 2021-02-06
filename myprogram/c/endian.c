#include <stdio.h>


int swapbit(char *ptr,int n)
{
	int i;
	for(i=0;i<n;i++){
		printf("%.2x",ptr[i]);
	}
	printf("\n");
}

void endcheck()
{
	int i=1;
	char *ptr = (char *)&i;
	if(*ptr == 1)
		printf("this is little endian \n");
	else
		printf("this is big endian \n");
}
int main()
{
	int x = 0x01234567;

	endcheck();

	swapbit((char *)&x,sizeof(x));
}
