#include <stdio.h>

int main()
{
	int *ptr ;
	int i;
	ptr = (int *)malloc(sizeof(int)*10);
	for(i=0;i<10;i++){
		ptr[i] = i*10;
	}
	for(i=0;i<10;i++){
		printf("%d ",ptr[i]);
	}
	printf(" add = %x %p\n",ptr,&ptr);
	ptr = (int *)realloc(ptr,sizeof(int)*10);
	for(i=10;i<20;i++){
		ptr[i] = i*10;
	}
	printf(" add = %x %p\n",ptr,&ptr);
	for(i=0;i<20;i++){
		printf("%d ",ptr[i]);
	}

}
