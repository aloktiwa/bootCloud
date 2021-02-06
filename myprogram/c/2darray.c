#include <stdio.h>

int main()
{
	int arr[5]={1,2,3,4,5};
	int arr1[5]={10,20,30,40,50};
	int (*p)[5];
	int *ptr[5]=arr;
	p[0]=arr;
	p[1]=arr1;
	p[2]=arr1;
	p[3]=arr1;
	printf("%d %d\n",*p[0]+1,*p[1]+2);
}
