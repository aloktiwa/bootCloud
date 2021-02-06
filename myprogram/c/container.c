#include <stdio.h>
#include <stddef.h>
#define container_of(ptr, type, member) ( {  \
		                const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
		                (type *)( (char *)__mptr - offsetof(type,member) ); });

#define mycon(ptr,type,member) ((type *)((char *)(ptr) - offsetof(type,member) ))

//((type *)((char *)(ptr) - offsetof(type,memebr) ))

// offset of 
//(char *)&((type *)0)->memeber
//((char *)&((type *)0)->member)

struct uname {
	char name[8];
	long df;
};
struct node {
	int aa;
	int bb;
	struct uname ll;
};
int main()
{
	struct node nd;
	struct uname *p = &nd.ll;
	printf("====== \n");
	struct node *pnd;
	struct node *qnd;
	pnd = container_of(p, struct node, ll);
	qnd = mycon(p, struct node, ll);
	printf(" %u %u %u\n",pnd,&nd,qnd);

}
