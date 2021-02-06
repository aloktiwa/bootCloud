
#include <stdio.h> 

int foo3(long long x)
{
	printf("%8x \n",x);
}

int foo2(int x) {
	foo3((long)x);
}
int foo() {
	foo2(0x12345678);
}

int main()  
{ 
   unsigned int i = 1; 
   unsigned char ii[4];
   char j=0;
   foo();
   char *c = (char*)&i; 
   if (*c)     
       printf("Little endian"); 
   else
       printf("Big endian"); 

   printf(" \n %x \n",&i);
   for(j=0;j<4;j++,c++)
	   printf("%2x %x %x \t",*c,c,&ii[j]);

   printf("\n");
   return 0; 
} 

