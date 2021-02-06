#include <stdio.h>
#include <stdint.h>

typedef struct Praseuint{
	unsigned int f1:1;
	unsigned int f2:2;
	unsigned int f3:3;
	unsigned int f4:4;
}Puint;

typedef struct Praseint {
	int f1:1;
	int f2:2;
	int f3:3;
	int f4:4;
}Pint;

unsigned int main()
{
	uint16_t i=0;
	Puint *d = &i;
	Pint *dm = &i;
	printf("%d %d %d %d\n",d->f1,d->f2,d->f3,d->f4);
	printf("%d %d %d %d\n",dm->f1,dm->f2,dm->f3,dm->f4);
	i=5;
	printf("%d %d %d %d\n",d->f1,d->f2,d->f3,d->f4);
	printf("%d %d %d %d\n",dm->f1,dm->f2,dm->f3,dm->f4);
}
