#include <stdio.h>
#include <string.h>


int main()
{
	char s1[] = {"modernforcomputer"};
	char s2[] = "For";

	if((void *)strcasestr(s1,s2) == NULL) {
		printf("here is not foun\n");
	} else {
		printf("here is foun\n");
	}
}
