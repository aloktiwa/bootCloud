int func() {
	return 0;
}

int anotherfunc()
{
	return 0;
}
#include <stdio.h>

struct 
{
   char *name;
   int (*funcptr)();
}
symtab[] = {
   "func", func,
   "anotherfunc", anotherfunc,
}; 



int main()
{
	printf("%s",symtab[1].name);
	printf("\r %s\n",symtab[0].name);
	   printf("\\new_c_question\by"); 
	      printf("geeksforgeeks"); 
}
