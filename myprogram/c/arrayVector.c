#include <stdio.h>
#include <stdlib.h>
#define OO_SHIFT = 16
#define OO_MASK = ((1 << OO_SHIFT) - 1)

	

int main()
{
	char *name[] = { "alok","INDIAN","1234567","99999999"};
	int numA[3][3] = {11,12,13,14,15,16,17,18,19};
	int *x = (int *)numA;
	char nn=0;
	int ptr = 100;
	unsigned int *uNi=&ptr;
	nn = sizeof(void);

	printf("numA == %d ",*x);//&x,*&&&&***x);
	printf("numA == %x %x ",&*x,&x);
	printf("numA == %d\n",*(&(&(&(*(*(*x)))))));

#if 1
	printf("%c nn =%d , %d \n",*(*(name)+2),nn,*uNi);
	printf("%c \n",name[1][2]);
	printf("%s ;;  %s ;; %s;;  %c \n",name[0],name[2],name[3],name[1][3]);
#endif
}
