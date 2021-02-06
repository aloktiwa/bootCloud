#include <stdio.h>


int main()
{

	int a_5[5] = {20,25,30,35,40};
	int *aa[5];
	int (*a)[5];
	a = a_5;
	int a1=10,a2=40,a3=30,a4=40,a5=50;
	aa[0] = &a1;aa[1] = &a2;aa[2]= &a3; aa[3]=&a4; aa[4] = &a5;
	for(int i=0;i<5;i++)
		printf("a[%d] = %d  %d\t",i,*(*a+i),*aa[i]);
}
