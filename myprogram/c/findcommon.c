#include <stdio.h>


int findcommon(const volatile int arr[],const int volatile brr[],const volatile int crr[], int a, int b , int c)
{
	int i=0,j=0,k=0;
	for(;i < a && j < b && k < c; )
	{
		if ( arr[i] == brr[j] == crr[k])
		{
			printf("find it i=%d val =%d \n",i,arr[i]);
			return 0;
		}
		else  if( (arr[i] > brr[j]) &&  (arr[i] > crr[k])) {
			i++;
		}
		else if(brr[j] > crr[k]) {
			j++;
		}
		else {
			k++;
		}
	}

	return 1;

}

int main()
{
	const volatile int arr[] = {2,7,17,28,40};
	volatile const int brr[] = {4,10,17,18,20};
	volatile const int crr[] = {6,15,17,38,60};
	if(findcommon(arr,brr,crr,5,5,5) == 0) {
		printf(" match find \n");
	}
	else {
		printf(" no common  find \n");
	}
}
