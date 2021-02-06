#include<stdio.h>

struct complex1 {
	double a;
	double b;
	char name[20];
}c;

struct Object {
	enum { CIR=0, REC, TRG} gCode;
	union {
		int size;
	};
};

int main()
{
 struct complex1 aA = {12,9,"hello"};

 int  A[] = {1,2,3,4,5};
 struct Object s1;
 void  *p,*q;
 int l;
 p=&s1;
 q=&A[3];


 printf("l = %d sizeof(s1) = %d \n",l = (q-p), sizeof(s1));
 printf("sizeof s1  = %d \n",l = (char *) (&s1 +1) -(char *)&s1);

	char cmd[200];
	printf("%lf %lf name %s \n",aA.a,aA.b,aA.name);
	memset(cmd,'\0',200);
	sprintf(cmd,"echo \"vslxos_enabled =%d is_vslxos_platform =%d bootenv_get_vslxos =%d \" > vslxos.txt \n",0,1,1);
//	system(cmd);
}

