#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char *ptr = (char *)malloc(10);
	int i;

	mtrace();
	printf("%d %x ",ptr,ptr);
	for(i=0;i<10;i++) {
		ptr[i] = 19+i;
	}
	for(i=0;i<10;i++) {
		printf("%d \t",ptr[i]);
	}

	ptr = realloc(ptr,1000);
	printf("\n %d %x \n",ptr,ptr);
	for(i=0;i<40;i++) {
		ptr[i] = 19+i;
	}
	for(i=0;i<1020;i++) {
		printf("%d \t",ptr[i]);
	}
}
