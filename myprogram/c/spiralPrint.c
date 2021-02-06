#include <stdio.h>

int main()
{
	volatile int c=1;
	int PL[4][4];
	int i,j,spi=1;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			PL[i][j] = i*j?i*j:(i+5);

		

	for(i=0;i<4;i++){
		if( spi) {
			spi=0;
			printf("\r");
			for(j=0;j<4;j++)
				printf("%d ",PL[i][j]);
		} else {
			spi=1;
			printf("\r\t");
			for(j=4-1;j>=0;j--)
				printf("%d ",PL[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
