#include <stdio.h>

//static long apple=10;
extern long apple;

extern int  foo();
void res(char *str)
{
	if(str == NULL) return ;

	int len=0;
	len = strlen(str);
	char c,*p1,*p2;
	p1 = str;
	p2 = str + (len -1);
	printf("len %d \n",len);
	while ((p1 != p2) && (*p1 != '\0') )
	{
		c = *p1; *p1 = *p2; *p2=c;
		p1++;p2--;
	}
}

int main(int arc , int argv[])

{
	char str[200];
	memset(str,'0',200);
	printf("Enter str ");
	scanf("%[^\n]",str);
/*	fgets(str,100,stdin); */
	printf("str =%s \n",str);
	res(str);
	printf("str =%s \n",str);

	for(int i=0;i<20;i++) {
		printf("tab %ld %ld\t",apple,foo());
	}
}
