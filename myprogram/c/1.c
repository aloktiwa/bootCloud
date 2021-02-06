#include <stdio.h> 
#include <linux/version.h>
  
char* fun() 
{ 
  return "I see you"; 
} 

unsigned long func(unsigned long n) {
	
	return((( n >> 24) & 0x000000ff ) | ((n << 24) & 0xff000000) | ((n << 8)& 0x00ff0000) | ((n>>8) & 0x0000ff00));
}
int main() 
{ 
	int i,count=0;
	unsigned long lp = 0xdeadbeef;
	printf("%p\n",&main);
	printf("%8X %8X %d\n",lp,func(lp),LINUX_VERSION_CODE);
	return 0;
	printf("%d %d %d %d \n",0/2,2/2,3/2,5/2);


  while(2) {
	if(++count > 5)break;
		printf("Hello count =%d \n",count);
  }
} 

