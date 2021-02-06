#include <stdio.h>

struct s {
	char a;
	char b;
	short d;
	int c;
}g;
int main()

{
g.b=9;
char *p = &g.a;
*p=40;
//	int typedef = ;
	int t = ( 100);
	typeof(int) B =800;
	printf("%d %d %d %d\n",&g.a,&g.b,&g.d,&g.c);
	printf("%d \n",&((struct s *)0)->a - &(struct s *)0);
//	printf("hellow %d %d  \n",t,(char *)(&(struct s *))0->b);
}
