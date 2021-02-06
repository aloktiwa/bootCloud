#include <stdio.h>

int main()
{
	int nums[] = {1,2,3,4,5,6,9};
	int i;
	int add1 = (9*(9+1))/2,add2=0;
	printf("add = %d \n",add1);

	for(i=0;i<(sizeof(nums)/4);i++)
	{
		add2 = add2 + nums[i];
	}
	printf("missing num %d",add1 - add2);
}
