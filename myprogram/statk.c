#include <stdio.h>
#include <stddef.h>

#define mcontainer_off(ptr,type,member)  ({					\
			const typeof(((type *)0)->member) *__mptr = (ptr);	\
			(type *)((char *)__mptr - offsetof(type,member)); })


struct namep {
	int age;
	long *base;
	char na[10];
};

struct namep gaa;
void fun(int *main_local_addr) 
{ 
    int fun_local; 
    if (main_local_addr < &fun_local) 
        printf("Stack grows upward\n"); 
    else
        printf("Stack grows downward\n"); 

	printf(" %u %u \n",main_local_addr,&fun_local);
} 
  
int main() 
{ 
	struct namep *aa = &gaa ;
	int *a = &aa->age;

	struct namep *bb;
	bb = mcontainer_off(a,struct namep,age);
	printf("%p %p \n",aa,bb);
    // fun's local variable 
    int main_local; 
  
    fun(&main_local); 
    return 0; 
} 
