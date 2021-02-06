#include <stdio.h>


void finddup(char *p,char *q) {
	printf(" size of int %d \n",sizeof(int));
	int h=0,H=0,x=1;
	int i;
	printf("%s %s\n",p,q);
	while(*p) {
		x=1;
		x = x << ( (*p) - 97);
//		printf("%d ",x);
		if( (h & x)  > 0 )
			printf("%c ",*p);
		else
			h = x | h;
		p++;
	}
	printf("  ");
	while(* q) { 
		x =1;
		x = x << ((*q) -97);
		if((H & x) > 0)
			printf("%c ",*q);
		else
			H = x | H;
		q++;
	}
	printf("\n");
	if( h == H)
		printf("this is amagrom\n");
}
int main()
{
	char name[] = "rmamashkarm";
	char name1[] = "mamashkarm";

	finddup(name,name1);
}
