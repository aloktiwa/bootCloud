#include <stdio.h>


int main()
{
	int A[] = { 1,2,3,4,-4,5,5,-6};

	int max=0,mul=1,i;

	for(i=0;i<7-2;i++) {
		mul = A[i]*A[i+1]*A[i+2];
		max = max > mul ? max:mul;
	}
	printf("%d %d \n",max,mul);
}
