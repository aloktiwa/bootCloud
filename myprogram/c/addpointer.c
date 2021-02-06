#include <stdio.h>

struct pnode {
	int dada;
	char name[20];
};
int main()
{
	struct pnode r1,r2;
	int n = 100,nn=10;
	void *p = &r1;
	void *k = &r2;
//	*k = 10;
	int r = (char *)(&r1 +1)  - (char *)(&r1);
	printf("%d %d\n",r,sizeof(r1));
}
