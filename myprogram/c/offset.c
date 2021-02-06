#include <stdio.h>


#define offsetof(type,member) ((size_t)&(((type *)0)->member))

typedef struct node {
	int val;
	int date;
	long c;
	//struct node *next;
}NODE;


int main()
{
	printf("OFFSET %d\n",offsetof(NODE,date));

	return 0;
}
