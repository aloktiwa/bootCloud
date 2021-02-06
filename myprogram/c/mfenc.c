#include <stdio.h>



int callmfenc()
{
	int ret ;
	asm volatile ("mfence" ::: "memory");
	asm ("mfence" ::: "memory");

	printf("ret = %d \n",ret);
	return ret;
}
int main(){
    printf("Disass me\n");
	callmfenc();
    asm volatile ("mfence" ::: "memory");
    return 0;
}

