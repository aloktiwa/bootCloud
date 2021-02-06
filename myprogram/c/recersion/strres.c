#include<stdio.h>
#include<string.h>
char * strresv1(char *str,int n){
	if(str[0] == '\0' || n <= 0)
		return str;
	else
		printf("%c",str[n]);
		n--;
		strresv1(str,n);
}

int main()
{
	char name[20]="malyalaM eman is";
	strresv1(name,strlen(name));
	printf("\n");
}
