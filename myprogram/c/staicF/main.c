#include <stdio.h>

long mohan=999;
extern int * getinstance();
void printmohan();
int main()
{
	int *ptr = getinstance();

	printf("mohan = %d, val = %d",mohan, *ptr = (*ptr + 120));
	printmohan();
}
