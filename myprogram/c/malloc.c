#include <stdio.h>
#include <stdlib.h>

struct internet {
	int pi;
	char *name;
};
int main(int argc, char **argv)
{
	struct internet *a1,*a2,*a3;
//	int typedef = 10;
	a1 = (struct internet *)malloc(sizeof(struct internet));
	a1->pi =100;
	a1->name = (char *)malloc(strlen(argv[1]));
	a2 = (struct internet *)malloc(sizeof(struct internet));
	a2->pi =200;
	printf("size argv[1] %d & argv[2] %d \n",strlen(argv[1]),strlen(argv[2]));
	a2->name = (char *)malloc(strlen(argv[2]));
	strcpy(a1->name,argv[1]);
	strcpy(a2->name,argv[2]);

	printf("%d %s \t %d %s \n",a1->pi,a1->name,a1->pi,a2->name);
#if 0
	int t =10;
	char A = 'A';

	int *ptr = (int *) malloc(sizeof(int));

	*ptr = 100;
	printf("<< %c %d >> \n",A,A);

	typeof(int) B =800;
	printf("hellow %d %d %d \n",t,B);
#endif
}
