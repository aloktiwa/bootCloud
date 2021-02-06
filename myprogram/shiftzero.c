#include <stdio.h>

void shiftzero(int *p,int n)
{
	int i=0,c=0,t;
	for(i=0;i<n;i++) {
			printf("%d ",p[i]);
	}
	for(i=0;i<n;i++) {
		if( p[i] != 0) {
			t = p[c];
			p[c] = p[i];
			p[i] = t;
			
			c++;
		}
	}
#if 0
	for(c;c<n;c++) {
		p[c] = 0;
	}
#endif
	printf("\n");
	for(i=0;i<n;i++) {
			printf("%d ",p[i]);
	}

}

int main()
{
	int array[] = {1,2,0,3,4,0,5,0,6,0,9,10};
	shiftzero(array,sizeof(array)/sizeof(array[0]));
}
