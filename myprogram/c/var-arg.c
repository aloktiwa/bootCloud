#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

#pragma GCC poison strcpy
#pragma GCC warning "COOL"
#pragma GCC error "what"
#pragma message "ok"

void sumx(int x ,int y, ...) {
	va_list vp;
	va_start(vp,x);
	int sum=y,num;

	while( num = va_arg(vp,int))
		sum +=num;

	assert(-1);
	va_end(vp);
	error
	printf(" sum =%d \n",sum);
}

int main()
{
	int x=10,y=90;
	printf("hellow \n");
	sumx(x,y,100,100,0);
}
