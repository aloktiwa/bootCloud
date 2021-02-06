#include <stdio.h>


int main()
{
	int name[] = {1,2,3,4,5,6,0,7,8,0,0,0,10,11};
	int *ptr,*ptr2,i;
	ptr = name;
	ptr2 = name;
	
	while(i++ < (sizeof(name) / 4))
	{
		if( *ptr != 0) {
			*ptr2 = *ptr; ptr2++;
		}
		ptr++;
	}

	while( ptr2 != ptr) {
		*ptr2 = 0;
		ptr2++;
	}
	for(i=0;i < 14;i++)
		printf("%d ",name[i]);
}
