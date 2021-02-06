#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



int main()
{
//	volatile int c=1;
	char c;
	int count;
	char buff[100];
	
	FILE *fp = fopen("file.txt","r");

	if(fp == NULL) {
		perror("open failed\n");
		return -1;
	}

	fseek(fp,-1L,SEEK_END);
	count = ftell(fp);
	while(count >= 0) {
		printf("%c",fgetc(fp));
		fseek(fp,-2L,SEEK_CUR);
		count--;
	}

#if 0

	while( (c=fgetc(fp)) != EOF) {
		printf("%c",c);
	}
#endif
	fclose(fp);
	printf("\n");
}
